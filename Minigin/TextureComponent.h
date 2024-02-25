//-----------------------------------------------------------------
// Main Game  File
// C++ Header - TextureComponent.h	
//-----------------------------------------------------------------

#pragma once
#include <memory>

#include "BaseComponent.h"
#include "Texture2D.h"

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// TextureComponent Class																
//-----------------------------------------------------------------
class TextureComponent : public dae::BaseComponent
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	TextureComponent(dae::GameObject& owner,const std::string filename);

	virtual ~TextureComponent() = default;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	TextureComponent(const TextureComponent& other) = delete;
	TextureComponent(TextureComponent&& other) noexcept = delete;
	TextureComponent& operator=(const TextureComponent& other) = delete;
	TextureComponent& operator=(TextureComponent&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------

	std::string GetName() const override;
	dae::Texture2D& GetTexture() const;
private:
	// -------------------------
	// Datamembers
	// -------------------------
	std::shared_ptr<dae::Texture2D> m_Texture;
};
