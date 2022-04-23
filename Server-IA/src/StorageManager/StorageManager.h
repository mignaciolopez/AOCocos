#ifndef STORAGE_MANAGER_H__
#define STORAGE_MANAGER_H__

#include "entt.hpp"

#include "BitStream.h"
#include <map>

#include "ECS/ECS_Log.h"

namespace ECS
{
	class StorageManager
	{
	public:
		StorageManager();
		~StorageManager();

		static StorageManager* getInstance();
		static void destroyInstace();


	private:
		
	};
}
#endif // !SIGNAL_MANAGER_H__