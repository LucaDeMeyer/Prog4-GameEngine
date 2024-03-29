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

		const glm::vec3& GetLocalPosition() const;
		//const glm::vec3& GetWorldPosition() const;

		void SetPosition(float x, float y, float z);

		void Update(float deltaTime) override;
		std::string GetName() const override;
	private:
		glm::vec3 m_Localposition{};
		//glm::vec3 m_WorldPosition{};
	};
}
