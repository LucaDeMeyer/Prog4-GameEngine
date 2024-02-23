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

void FPSComponent::Update(float deltaTime) {
    static float elapsedTime = 0.0f;
    static int frameCount = 0;

    elapsedTime += deltaTime;
    frameCount++;

    if (elapsedTime >= 1.0f) {
        float fps = static_cast<float>(frameCount) / elapsedTime;
        std::cout << "FPS: " << fps << std::endl;

        elapsedTime = 0.0f;
        frameCount = 0;
    }
}

std::string FPSComponent::GetName() const
{
    return "FPSComponent";
}

