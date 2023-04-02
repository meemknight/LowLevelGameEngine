#pragma once

namespace LLGE
{
	namespace GameObject
	{
		class Component
		{
		public:
			Component();
			virtual ~Component();

			virtual bool init(){}
			virtual bool awake(){}

			virtual bool update(float deltaTime){}
			virtual bool lateUpdate(float deltaTime){}

			virtual bool cleanUp(){}
		protected:

		};
	}
}