//-----------------------------------------------------------------
// Main Game File
// C++ Source - TextureComponent.cpp - version v7_02
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "TextureComponent.h"																				

#include <windows.h>

#include "ResourceManager.h"

//-----------------------------------------------------------------
// TextureComponent methods																				
//-----------------------------------------------------------------

TextureComponent::TextureComponent(dae::GameObject& owner, std::string filename) : BaseComponent(owner)

{
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

std::string TextureComponent::GetName() const
{
	return "Texture Component";
}

dae::Texture2D& TextureComponent::GetTexture() const
{
	return *m_Texture;
}

