#include "StorageManager.h"

namespace ECS
{
	StorageManager::StorageManager()
	{
		ECS_Log::s_consoleL->trace("[StorageManager] Constructor");

	}

	StorageManager::~StorageManager()
	{
		ECS_Log::s_consoleL->trace("[StorageManager] Destructor");
	}

	static StorageManager* s_storageManager = nullptr;

	StorageManager * StorageManager::getInstance()
	{
		ECS_Log::s_consoleL->trace("[StorageManager] Call to getInstance.");
		if (!s_storageManager)
		{
			ECS_Log::s_consoleL->trace("[StorageManager] s_signalsManager is nullptr");
			s_storageManager = new (std::nothrow) StorageManager;
		}

		return s_storageManager;
	}

	void StorageManager::destroyInstace()
	{
		if (s_storageManager)
		{
			delete s_storageManager;
			s_storageManager = nullptr;
		}
	}
}