//-----------------------------------------------------------------
// Main Game  File
// C++ Header - FPSComponent.h		
//-----------------------------------------------------------------

#pragma once


//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "BaseComponent.h"
#include "GameObject.h"

//-----------------------------------------------------------------
// FPSComponent Class																
//-----------------------------------------------------------------
namespace dae
{
	class TextComponent;
	class FPSComponent : public BaseComponent
	{
	public:
		//---------------------------
		// Constructor(s) and Destructor
		//---------------------------
		explicit FPSComponent(GameObject* owner) : BaseComponent(owner)
		{
			if(owner->HasComponent<TextComponent>())
			text = owner->GetComponent<TextComponent>();
		}

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
		float GetFps()& { return m_Fps; }
	private:
		float m_Fps{};
		TextComponent* text;

	};
}
