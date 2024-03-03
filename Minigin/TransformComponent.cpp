#include "TransformComponent.h"

#include "GameObject.h"
#include "TextComponent.h"
#include <glm/gtc/matrix_transform.hpp>

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
			m_WorldPosition = GetOwner()->GetParent()->GetComponent<TransformComponent>()->m_WorldPosition + m_LocalPosition;
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

	m_WorldPosition = m_LocalPosition;
}

void dae::TransformComponent::Update(float)
{
	if(m_RotationComponent)
	{
		const float rotation = m_RotationComponent->GetRotationAngle();
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	}
}

