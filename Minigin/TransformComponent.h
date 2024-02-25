#pragma once
#include <glm/glm.hpp>

#include "BaseComponent.h"

namespace dae
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(GameObject& owner) : BaseComponent(owner) , m_position(){}
		~TransformComponent() override = default;

		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) noexcept = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) noexcept = delete;

		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
		std::string GetName() const override;
	private:
		glm::vec3 m_position;
	};
}
