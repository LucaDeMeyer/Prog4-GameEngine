#include "TransformComponent.h"

const glm::vec3& dae::TransformComponent::GetLocalPosition() const
{
	return m_Localposition;
}



void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_Localposition.x = x;
	m_Localposition.y = y;
	m_Localposition.z = z;
}

void dae::TransformComponent::Update(float)
{
}

std::string dae::TransformComponent::GetName() const
{
	return "TransformComponent";
}
