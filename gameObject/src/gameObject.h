#pragma once
#include "uuid.h"
#include <vector>


namespace LLGE
{
	namespace GameObject
	{
		class Component;
		class GameObject
		{
		public:
			GameObject();
			~GameObject();

			void awake();
			void init();

			void update(float deltaTime);

			inline std::vector<Component>& getComponents() {};
			void addComponent(Component component);
			void deleteComponent(std::reference_wrapper<Component> component);

		private:
			LLGE::Utils::UUID m_UUID;
			std::vector<std::unique_ptr<Component>> m_Components;
		};
	}
}
//  GameObjectManager add delete update factory
//	GameObject
//		-> vector <Components> 
//	