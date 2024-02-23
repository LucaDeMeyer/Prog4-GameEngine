//-----------------------------------------------------------------
// Main Game  File
// C++ Header - FPSComponent.h		
//-----------------------------------------------------------------

#pragma once


//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "BaseComponent.h"
//-----------------------------------------------------------------
// FPSComponent Class																
//-----------------------------------------------------------------
class FPSComponent : public BaseComponent
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	explicit FPSComponent(dae::GameObject& owner) : BaseComponent(owner){}

	~FPSComponent() override = default;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	FPSComponent(const FPSComponent& other) = delete;
	FPSComponent(FPSComponent&& other) noexcept = delete;
	FPSComponent& operator=(const FPSComponent& other) = delete;
	FPSComponent& operator=(FPSComponent&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------
	 void Update(float deltaTime) override;
	 std::string GetName() const override;



};
