//-----------------------------------------------------------------
// Main Game  File
// C++ Header - RotationComponent.h		
//-----------------------------------------------------------------

#pragma once
#include "BaseComponent.h"

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
namespace dae
{


	//-----------------------------------------------------------------
	// RotationComponentClass																
	//-----------------------------------------------------------------
	class RotationComponent : public BaseComponent
	{
	public:
		//---------------------------
		// Constructor(s) and Destructor
		//---------------------------
		RotationComponent(GameObject* owner,const float angle = 0) : BaseComponent(owner) , m_RotationAngle(angle){}

		~RotationComponent() override = default;

		//---------------------------
		// Disabling copy/move constructors and assignment operators   
		//---------------------------
		RotationComponent(const RotationComponent& other)					= delete;
		RotationComponent(RotationComponent&& other) noexcept				= delete;
		RotationComponent& operator=(const RotationComponent& other)		= delete;
		RotationComponent& operator=(RotationComponent&& other) noexcept	= delete;

		//---------------------------
		// General Methods
		//---------------------------

		void Update(float deltaTime) override;

		float GetRotationAngle() const { return m_RotationAngle; }
	private:
		// -------------------------
		// Datamembers
		// -------------------------
		float m_RotationAngle;

	};
}
