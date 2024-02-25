#pragma once
#include <memory>
#include <vector>


namespace dae
{

	class Texture2D;
	class BaseComponent;

	// todo: this should become final.
	class GameObject final
	{
	public:
		 void Update(float deltaTime);
		 void Render() const;

		void SetPosition(float x, float y);

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;


		//Component Managment

		void AddComponent(BaseComponent* component);
		void RemoveComponent(const std::string& componentName);
		BaseComponent* GetComponent(const std::string& componentName) const;
		bool HasComponent(const std::string& componentName) const;

		
	private:
		std::vector<BaseComponent*> m_Components;

	};
}
