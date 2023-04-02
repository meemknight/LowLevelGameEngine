#pragma once
#include <component.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace LLGE
{	
namespace GameObject
{
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();


		inline glm::vec3& getPosition() { return m_Position; }
		inline glm::fquat& getRotation() { return m_Rotation; }
		inline glm::vec3& getScale() { return m_Scale; }



	public:
		glm::vec3 localPosition;
		glm::fquat localRotation;
		glm::vec3 localScale;

		glm::mat4x4 localTransform;
	private:
		glm::vec3 m_Position;
		glm::fquat m_Rotation;
		glm::vec3 m_Scale;

		glm::mat4x4 m_Transform;
	};
}
}