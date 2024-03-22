
#pragma once
#include <glm/glm.hpp>

#include "BaseComponent.h"
#include "GameObject.h"

namespace dae
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(GameObject* owner) : BaseComponent(owner)
		{
			
		}
		~TransformComponent() override = default;

		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) noexcept = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) noexcept = delete;

		const glm::vec3& GetLocalPosition() const { return m_LocalPosition; }
		const glm::vec3& GetWorldPosition();
		void UpdateWorldPosition();

		void SetLocalPosition(glm::vec3 newpos);
		void SetWorldPosition(glm::vec3 newpos);

		void SetPosition(float x, float y, float z);
		bool SetPositionDirty() { return m_PositionIsDirty = true; }

		void Update(float deltaTime) override;


	private:
		glm::vec3 m_LocalPosition{};
		glm::vec3 m_WorldPosition{};
		bool m_PositionIsDirty{};
		


	};
}
