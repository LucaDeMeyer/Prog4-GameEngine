#pragma once
#include <memory>
#include <vector>
#include "Transform.h"

class BaseComponent;
namespace dae
{

	class Texture2D;


	// todo: this should become final.
	class GameObject 
	{
	public:
		virtual void Update(float deltaTime);
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;


		//Component Managment

		void AddComponent(std::unique_ptr<BaseComponent> component);
		void RemoveComponent(const std::string& componentName);
		BaseComponent* GetComponent(const std::string& componentName) const;
		bool HasComponent(const std::string& componentName) const;

	private:
		Transform m_transform{};
		std::vector<std::unique_ptr<BaseComponent>> m_Components;
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};// make component?
	};
}
