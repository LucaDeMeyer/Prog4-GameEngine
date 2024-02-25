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
        if (comp->GetName() == "FPSComponent")
        {
            dynamic_cast<FPSComponent*>(comp)->Update(deltaTime);
        }
        if(comp->GetName() == "TextComponent")
        {
            dynamic_cast<TextComponent*>(comp)->Update();
        }
	}
}

void dae::GameObject::Render() const
{
    TextureComponent* textureComp = nullptr;
    TransformComponent* transformComp = nullptr;

    // Find TextureComponent and TransformComponent
    for (auto comp : m_Components)
    {
        if (comp->GetName() == "TextureComponent")
        {
            textureComp = dynamic_cast<TextureComponent*>(comp);
        }
        else if (comp->GetName() == "TransformComponent")
        {
            transformComp = dynamic_cast<TransformComponent*>(comp);
        }
    }
    // Check if both components are present
    if (textureComp && transformComp)
    {
        // Render using RenderComponent (assuming RenderComponent is also present)
       BaseComponent* renderComp = GetComponent("RenderComponent");
       if (renderComp)
       {
           dynamic_cast<RenderComponent*>(renderComp)->Render(textureComp->GetTexture(), *transformComp);
       }
       else
           std::cout << "render not found\n";
    }
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
    m_Components.push_back(component);
}

void dae::GameObject::RemoveComponent(const std::string& componentName)
{
    const auto newEnd = std::remove_if(m_Components.begin(), m_Components.end(),
        [&](const BaseComponent* comp) {
            return comp->GetName() == componentName;
        });

    // Erase the removed elements from the vector
    m_Components.erase(newEnd, m_Components.end());
}

dae::BaseComponent* dae::GameObject::GetComponent(const std::string& componentName) const
{
    for (const auto& comp : m_Components) {
        if (comp->GetName() == componentName) {
            return comp;
        }
    }
    return nullptr;
}

bool dae::GameObject::HasComponent(const std::string& componentName) const
{
    return GetComponent(componentName);
}
