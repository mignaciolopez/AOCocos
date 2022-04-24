#ifndef HUD_COMPONENT_H__
#define HUD_COMPONENT_H__

#include "cocos2d.h"
#include "Graphics/Interface.h"

class HudComponent final
{
public:
	HudComponent(cocos2d::Scene* scene)
	{
#ifdef _DEBUG
		cocos2d::log("[HudComponent] Constructor");
#endif
		cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
		_clippingSize = cocos2d::Size(544, 417);
		 _clippingPos = cocos2d::Vec2(10, 45);

		//HUD NODE
		_hudNode = cocos2d::Node::create();
		scene->addChild(_hudNode, 1);

		//stencil
		m_stencil = cocos2d::DrawNode::create();
		m_stencil->drawSolidRect(_clippingPos, _clippingPos + _clippingSize, cocos2d::Color4F::GREEN);

		//VIEW MAP NODE
		_clippingNode = cocos2d::ClippingNode::create();
		_clippingNode->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
		_clippingNode->setIgnoreAnchorPointForPosition(false);
		_clippingNode->setPosition(cocos2d::Vec2::ZERO);
		_clippingNode->setStencil(m_stencil);
		_clippingNode->setInverted(true);
		_hudNode->addChild(_clippingNode, 1);
		
		//HUD Label position
		cocos2d::TTFConfig ttf("fonts/American Typewriter.ttf", 12.0f);
		ttf.bold = true;
		_lblPosition = cocos2d::Label::createWithTTF(ttf, "- -", cocos2d::TextHAlignment::LEFT);
		_lblPosition->setPosition(cocos2d::Vec2(625, 24));
		_lblPosition->setVisible(true);
		_hudNode->addChild(_lblPosition, 4);

		//HUD SPRITES
		float csf = cocos2d::Director::getInstance()->getContentScaleFactor();
		//mainWindow
		_mainWindow = cocos2d::Sprite::createWithSpriteFrameName(TP::Interface::ventanaPrincipal);
		_mainWindow->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
		_clippingNode->addChild(_mainWindow, 1);

		//Inventory
		_sprInventory = cocos2d::Sprite::createWithSpriteFrameName(TP::Interface::centroInventario);
		_sprInventory->setAnchorPoint(cocos2d::Vec2(0, 0));
		_sprInventory->setPosition(580, 200);
		_sprInventory->setVisible(true);
		_hudNode->addChild(_sprInventory, 5);

		//Spells
		_sprSpells = cocos2d::Sprite::createWithSpriteFrameName(TP::Interface::centroHechizos);
		_sprSpells->setAnchorPoint(cocos2d::Vec2(0, 0));
		_sprSpells->setPosition(580, 200);
		_sprSpells->setVisible(false);
		_hudNode->addChild(_sprSpells, 6);
	}

	~HudComponent()
	{
#ifdef _DEBUG
		cocos2d::log("[HudComponent] Destructor");
#endif
	}

	cocos2d::Node* _hudNode;
	cocos2d::ClippingNode* _clippingNode;

	//LABELS
	cocos2d::Label* _lblPosition;

	//SPRITES
	cocos2d::Sprite* _mainWindow;
	cocos2d::Sprite* _sprInventory;
	cocos2d::Sprite* _sprSpells;

	cocos2d::Size _clippingSize;
	cocos2d::Vec2 _clippingPos;

private:
	cocos2d::DrawNode* m_stencil;

};

#endif // !HUD_COMPONENT_H__