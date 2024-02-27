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



std::string dae::TextureComponent::GetName() const
{
		return "Texture Component";
}

dae::Texture2D& dae::TextureComponent::GetTexture() const
{
	return *m_Texture;
}

void dae::TextureComponent::SetTexture(std::shared_ptr<Texture2D> newTexture)
{
	m_Texture = std::move(newTexture);
}

void dae::TextureComponent::LoadTexture(const std::string& filename)
{
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::TextureComponent::Update(float)
{

}


