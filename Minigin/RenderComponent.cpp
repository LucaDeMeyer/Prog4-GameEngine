//-----------------------------------------------------------------
// Main Game File
// C++ Source - RenderComponent.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "RenderComponent.h"																				

#include "Renderer.h"
#include "TransformComponent.h"

//-----------------------------------------------------------------
// RenderComponent methods																				
//-----------------------------------------------------------------


void dae::RenderComponent::Render(const dae::Texture2D& texture, const dae::TransformComponent& transform) const
{
	const auto& pos = transform.GetLocalPosition();
	dae::Renderer::GetInstance().RenderTexture(texture, pos.x, pos.y);
}

void dae::RenderComponent::Update(float )
{
	
}


