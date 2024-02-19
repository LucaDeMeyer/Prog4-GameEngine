//-----------------------------------------------------------------
// Main Game  File
// C++ Header - BaseComponent.h - version v7_02			
//-----------------------------------------------------------------

#pragma once

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


	virtual ~BaseComponent();

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




private:
	// -------------------------
	// Datamembers
	// -------------------------
	BaseComponent();

};
