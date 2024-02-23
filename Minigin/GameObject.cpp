#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime)
{
	
}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(std::unique_ptr<BaseComponent> component)
{
    m_Components.push_back(std::move(component));
}

void dae::GameObject::RemoveComponent(const std::string& componentName)
{
    m_Components.erase(std::remove_if(m_Components.begin(), m_Components.end(),
        [&](const std::unique_ptr<BaseComponent>& comp) {
            return comp->GetName() == componentName;
        }), m_Components.end());
}

BaseComponent* dae::GameObject::GetComponent(const std::string& componentName) const
{
    for (const auto& comp : m_Components) {
        if (comp->GetName() == componentName) {
            return comp.get();
        }
    }
    return nullptr;
}

bool dae::GameObject::HasComponent(const std::string& componentName) const
{
    return GetComponent(componentName);
}
