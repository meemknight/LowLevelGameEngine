#include "transform.h"

LLGE::GameObject::Transform::Transform() 
	: m_Position(0.f), m_Rotation(1.f, 0.f, 0.f, 0.f), m_Scale(1.f),
	  localPosition(0.f), localRotation(1.f, 0.f, 0.f, 0.f), localScale(1.f),
	  m_Transform(0.f), localTransform(0.f)
	 
{
	
}

LLGE::GameObject::Transform::~Transform()
{
}
