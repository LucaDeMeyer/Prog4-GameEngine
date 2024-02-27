#include "TransformComponent.h"

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::TransformComponent::Update(float)
{
}

std::string dae::TransformComponent::GetName() const
{
	return "TransformComponent";
}
