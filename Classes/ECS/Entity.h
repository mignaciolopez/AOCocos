#pragma once

#include <vector>

using ContainerComponents = std::vector<void*>;

class Entity
{
public:
	Entity();
	~Entity();

	void AddComponent(void* component);
	unsigned int GetNumOfComponents();

private:
	ContainerComponents m_components;

};
