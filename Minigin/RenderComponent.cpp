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


void RenderComponent::Render(const dae::Texture2D& texture, const dae::TransformComponent& transform) const
{
	const auto& pos = transform.GetPosition();
	dae::Renderer::GetInstance().RenderTexture(texture, pos.x, pos.y);
}

std::string RenderComponent::GetName() const
{
	return "RenderComponent";
}
