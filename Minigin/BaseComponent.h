//-----------------------------------------------------------------
// Main Game  File
// C++ Header - BaseComponent.h - version v7_02			
//-----------------------------------------------------------------

#pragma once
#include <string>

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// BaseComponent Class																
//-----------------------------------------------------------------
class BaseComponent 
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------


	virtual ~BaseComponent() =default;
	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) noexcept = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------
	virtual void Update(float deltaTime) = 0;
	virtual std::string GetName() const = 0;



private:
	// -------------------------
	// Datamembers
	// -------------------------


};
