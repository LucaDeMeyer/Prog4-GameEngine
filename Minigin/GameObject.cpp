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

