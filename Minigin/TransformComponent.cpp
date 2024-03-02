#include "TransformComponent.h"

#include "GameObject.h"
#include "TextComponent.h"

const glm::vec3& dae::TransformComponent::GetWorldPosition()
{
	if (m_PositionIsDirty)
		UpdateWorldPosition();
	return m_WorldPosition;
}

void dae::TransformComponent::UpdateWorldPosition()
{
	if (m_PositionIsDirty)
	{
		if (GetOwner()->GetParent() == nullptr)
			m_WorldPosition = m_LocalPosition;
		else
			m_WorldPosition = GetWorldPosition() + m_LocalPosition;
	}
	m_PositionIsDirty = false;
}

void dae::TransformComponent::SetLocalPosition(glm::vec3 newpos)
{
	m_LocalPosition = newpos;
	SetPositionDirty();
}

void dae::TransformComponent::SetWorldPosition(glm::vec3 newpos)
{
	if (!GetOwner()->IsChild(GetOwner()))
	{
		m_LocalPosition = m_WorldPosition;
	}
	else
		m_WorldPosition = newpos;
}

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
