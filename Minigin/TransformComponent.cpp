#include "TransformComponent.h"

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::TransformComponent::Update(float)
{

}

std::string dae::TransformComponent::GetName() const
{
	return "TransformComponent";
}
