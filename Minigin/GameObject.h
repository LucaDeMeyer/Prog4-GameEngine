#pragma once
#include <memory>
#include <vector>


namespace dae
{

	class Texture2D;
	class BaseComponent;

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


		//Component managment
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

	private:
		std::vector<BaseComponent*> m_Components;

	};
}
