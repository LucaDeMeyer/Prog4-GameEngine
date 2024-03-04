#pragma once
#include <memory>
#include <vector>
#include <glm/vec3.hpp>




namespace dae
{

	class Texture2D;
	class BaseComponent;
	class TransformComponent;

	class GameObject final
	{
	public:
		 void Update(float deltaTime);
		 void Render() const;

		

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;


		//Component management
		void AddComponent(BaseComponent* component);

		template <typename T>
		void RemoveComponent()
		{
			auto it = std::remove_if(m_Components.begin(), m_Components.end(),
				[typeidT = &typeid(T)](BaseComponent* component)
				{
					return typeid(*component) == *typeidT;
				});

			m_Components.erase(it, m_Components.end());
		}

		
		template <typename T>
		bool HasComponent() const
		{
			return GetComponent<T>() != nullptr;
		}

		template <typename T>
		T* GetComponent() const
		{
			for (BaseComponent* component : m_Components)
			{
				// Check if the dynamic cast is successful
				T* derivedComponent = dynamic_cast<T*>(component);
				if (derivedComponent != nullptr)
				{
					return derivedComponent;
				}
			}
			return nullptr;
		}

		//SceneGraph
		void SetParent(GameObject* parent, bool keepWorldPosition);
		void RemoveChild(GameObject* child);
		void AddChild(GameObject* child);

		GameObject* GetChildAtIndex(int index) const { return m_Children[index]; }
		size_t GetChildCount() const { return m_Children.size(); }

		bool IsChild(const GameObject* parent);

		const GameObject* GetParent() const { return m_Parent; }

	private:

		std::vector<BaseComponent*> m_Components;

		std::vector<GameObject*> m_Children;
		GameObject* m_Parent				{nullptr};

		glm::vec3 m_LocalPosition;
		glm::vec3 m_WorldPosition;

		TransformComponent* m_Transform;
	};
}
