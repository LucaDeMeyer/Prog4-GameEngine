#include <string>
#include "BaseComponent.h"
#include "GameObject.h"

#include <iostream>

#include "FPSComponent.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"


dae::GameObject::~GameObject()
{
	for(auto comp : m_Components)
	{

        delete comp;
	}
}

void dae::GameObject::Update(float deltaTime)
{
    for(auto comp : m_Components)
    {
        comp->Update(deltaTime);
    }

}

void dae::GameObject::Render() const
{
    //expensive -> should add datamembers that get set at creation
    if(HasComponent<TextureComponent>() && HasComponent<RenderComponent>() && HasComponent<TransformComponent>())
    GetComponent<RenderComponent>()->Render(GetComponent<TextureComponent>()->GetTexture(), *GetComponent<TransformComponent>());
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
    m_Components.emplace_back(component);
}


void dae::GameObject::SetParent(dae::GameObject* parent, bool keepWorldPosition)
{
    if (m_Transform == nullptr)
        m_Transform = GetComponent<TransformComponent>();

    if (IsChild(parent) || parent == this || m_Parent == parent)
        return;
    if (parent == nullptr)
        m_Transform->SetLocalPosition(m_Transform->GetWorldPosition());
    else
    {
        if (keepWorldPosition)
            m_Transform->SetLocalPosition(m_Transform->GetLocalPosition() - parent->m_Transform->GetWorldPosition());
        m_Transform->SetPositionDirty();
    }
    if (m_Parent) m_Parent->RemoveChild(this);
    m_Parent = parent;
    if (m_Parent) m_Parent->AddChild(this);
}
void dae::GameObject::RemoveChild(GameObject* child)
{
    auto it = std::remove(m_Children.begin(), m_Children.end(), child);
    m_Children.erase(it, m_Children.end());
    child->m_Parent = nullptr;
}

void dae::GameObject::AddChild(GameObject* child)
{
    const auto it = std::find(m_Children.begin(), m_Children.end(), child);
    if (it == m_Children.end())
    {
        m_Children.emplace_back(child);
        child->m_Parent = this; 
    }
}

bool dae::GameObject::IsChild(const GameObject* parent)
{
    if (parent->m_Parent == nullptr)
        return false;

    return true;

}
