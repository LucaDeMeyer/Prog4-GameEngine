//-----------------------------------------------------------------
// Main Game File
// C++ Source - FPSComponent.cpp - version v7_02
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "FPSComponent.h"																				

#include <iostream>

//-----------------------------------------------------------------
// FPSComponent methods																				
//-----------------------------------------------------------------

void dae::FPSComponent::Update(float deltaTime) {
    static float elapsedTime = 0.0f;
    static int frameCount = 0;

    elapsedTime += deltaTime;
    frameCount++;

    if (elapsedTime >= 1.0f) {
        m_Fps = static_cast<float>(frameCount) / elapsedTime;
        std::cout << "FPS: " << m_Fps << std::endl;

        elapsedTime = 0.0f;
        frameCount = 0;
    }
}

std::string dae::FPSComponent::GetName() const
{
    return "FPSComponent";
}

