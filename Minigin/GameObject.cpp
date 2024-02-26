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
    //can only update component directly-> impliment update in basecomp -> pure virtual/ virtual
    GetComponent<FPSComponent>()->Update(deltaTime);
    GetComponent<TextComponent>()->Update();

}

void dae::GameObject::Render() const
{
    GetComponent<RenderComponent>()->Render(GetComponent<TextureComponent>()->GetTexture(), *GetComponent<TransformComponent>());
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
    m_Components.emplace_back(component);
}

