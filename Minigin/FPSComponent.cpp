//-----------------------------------------------------------------
// Main Game File
// C++ Source - FPSComponent.cpp - version v7_02
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "FPSComponent.h"																				

#include <iomanip>
#include <iostream>
#include<sstream>
#include "TextComponent.h"

//-----------------------------------------------------------------
// FPSComponent methods																				
//-----------------------------------------------------------------

void dae::FPSComponent::Update(float deltaTime) {

    if(m_TextComp == nullptr)
		m_TextComp = GetOwner()->GetComponent<TextComponent>();
    static float elapsedTime = 0.0f;
    static int frameCount = 0;

    elapsedTime += deltaTime;
    frameCount++;

    if (elapsedTime >= 1.0f) {
        m_Fps = static_cast<float>(frameCount) / elapsedTime;
        std::stringstream text;
        text << std::fixed << std::setprecision(1) << std::to_string(m_Fps * 10)  << "FPS";
        if(m_TextComp!=nullptr)
        m_TextComp->SetText(text.str());
        elapsedTime = 0.0f;
        frameCount = 0;
    }
}

