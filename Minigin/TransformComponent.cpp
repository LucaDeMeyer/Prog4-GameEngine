#include "TransformComponent.h"

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;
}

void dae::TransformComponent::Update(float)
{
}

std::string dae::TransformComponent::GetName() const
{
	return "TransformComponent";
}
