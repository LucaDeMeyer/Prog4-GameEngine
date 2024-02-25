//-----------------------------------------------------------------
// Main Game  File
// C++ Header - RenderComponent.h		
//-----------------------------------------------------------------

#pragma once
#include "BaseComponent.h"

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

namespace dae
{
	class TransformComponent;
	class Texture2D;
}

//-----------------------------------------------------------------
// RenderComponentClass																
//-----------------------------------------------------------------
class RenderComponent :public dae::BaseComponent
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	RenderComponent(dae::GameObject& owner) : BaseComponent(owner){}

	~RenderComponent() override = default ;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	RenderComponent(const RenderComponent& other) = delete;
	RenderComponent(RenderComponent&& other) noexcept = delete;
	RenderComponent& operator=(const RenderComponent& other) = delete;
	RenderComponent& operator=(RenderComponent&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------

	void Render(const dae::Texture2D& texture, const dae::TransformComponent& transform) const;
	std::string GetName() const override;
private:
	// -------------------------
	// Datamembers
	// -------------------------


};
