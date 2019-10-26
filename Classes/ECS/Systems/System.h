#ifndef __SYSTEM_H__
#define __SYSTEM_H__

namespace ECS
{

	class System
	{
	public:
		System();
		~System();

		virtual void Update() = 0;
	};
}
#endif // __SYSTEM_H__