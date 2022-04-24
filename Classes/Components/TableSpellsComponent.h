#ifndef TABLE_SPELLS_COMPONENT_H__
#define TABLE_SPELLS_COMPONENT_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class TBSpellsComponent :
	public cocos2d::extension::TableViewDataSource,
	public cocos2d::extension::TableViewDelegate
{
public:
	TBSpellsComponent(cocos2d::Node* hudNode)
	{
#ifdef _DEBUG
		cocos2d::log("[TBSpellsComponent] Constructor");
#endif
		_rows = 25;
		_tableSpells = cocos2d::extension::TableView::create(this, m_size);
		_tableSpells->setDirection(cocos2d::extension::ScrollView::Direction::VERTICAL);
		_tableSpells->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
		_tableSpells->setPosition(m_pos);
		_tableSpells->setDelegate(this);
		_tableSpells->setVerticalFillOrder(cocos2d::extension::TableView::VerticalFillOrder::TOP_DOWN);
		_tableSpells->setBounceable(false);
		_tableSpells->setVisible(false);
		_tableSpells->setColor(cocos2d::Color3B(120, 120, 255));
		hudNode->addChild(_tableSpells, 7);
		_tableSpells->reloadData();
	}

	~TBSpellsComponent()
	{
#ifdef _DEBUG
		cocos2d::log("[TBSpellsComponent] Destructor");
#endif
	}

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) override
	{

	}
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) override
	{
	}

	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell) override
	{
#if _DEBUG
		cocos2d::log("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
#endif

		_selected = static_cast<long>(cell->getIdx());
	}

	virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx) override
	{
		return cocos2d::Size(m_size.width, 18.1f);
	}

	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx) override
	{
		auto cell = table->cellAtIndex(idx);

		if (cell)
		{
			auto label = dynamic_cast<cocos2d::Label*>(cell->getChildByTag(idx));
			if (label)
			{
				label->setString("Apocalipsis - " + std::to_string(static_cast<long>(idx)));
			}
			else
			{
				label = cocos2d::Label::createWithSystemFont("Apocalipsis - " + std::to_string(static_cast<long>(idx)), "arial", 16.0f);
				label->setPosition(cocos2d::Vec2::ZERO);
				label->setAnchorPoint(cocos2d::Vec2::ZERO);
				label->setTag(static_cast<long>(idx));
				cell->addChild(label);
			}
		}
		else
		{
			cell = new (std::nothrow) cocos2d::extension::TableViewCell;
			cell->autorelease();

			cell->setIdx(idx);

			auto label = cocos2d::Label::createWithSystemFont("Apocalipsis - " + std::to_string(static_cast<long>(idx)), "arial", 16.0f);
			label->setPosition(cocos2d::Vec2::ZERO);
			label->setAnchorPoint(cocos2d::Vec2::ZERO);
			label->setTag(static_cast<long>(idx));
			cell->addChild(label);
		}
		
		return cell;
	}

	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table) override
	{
		return _rows;
	}

	int _selected = -1;
	cocos2d::extension::TableView* _tableSpells;
	ssize_t _rows;

private:
	cocos2d::Size m_size = cocos2d::Size(166, 181);
	cocos2d::Vec2 m_pos = cocos2d::Vec2(593, 257);

};

#endif // !TABLE_SPELLS_COMPONENT_H__