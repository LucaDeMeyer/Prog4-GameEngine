#pragma once
#include <glm/glm.hpp>

#include "BaseComponent.h"

namespace dae
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(GameObject* owner) : BaseComponent(owner){}
		~TransformComponent() override = default;

		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) noexcept = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) noexcept = delete;

		const glm::vec3& GetLocalPosition() const{ return m_LocalPosition; }
		const glm::vec3& GetWorldPosition() const { return m_WorldPosition; }

		void SetLocalPosition(glm::vec3 newpos) { m_LocalPosition = newpos; }

		void SetPosition(float x, float y, float z);

		void Update(float deltaTime) override;
		std::string GetName() const override;
	private:
		glm::vec3 m_LocalPosition{};
		glm::vec3 m_WorldPosition{};
		
	};
}
