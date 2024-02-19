//-----------------------------------------------------------------
// Main Game  File
// C++ Header - ComponentFactory.h - version v7_02			
//-----------------------------------------------------------------

#pragma once
#include <memory>
#include <vector>

#include "BaseComponent.h"

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// ComponentFactory Class																
//-----------------------------------------------------------------
class ComponentFactory 
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------

    template <typename T, typename... Args>
    static T& CreateComponent(Args&&... args) {
        components.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        return *static_cast<T*>(components.back().get());
    }

    template <typename T>
    static void RemoveComponent() {
        auto it = std::remove_if(components.begin(), components.end(),
            [](const std::unique_ptr<BaseComponent>& comp) {
                return dynamic_cast<T*>(comp.get()) != nullptr;
            });

        components.erase(it, components.end());
    }

    template <typename T>
    static T* GetComponent() {
        for (const auto& comp : components) {
            if (auto typedComp = dynamic_cast<T*>(comp.get())) {
                return typedComp;
            }
        }
        return nullptr;
    }

    template <typename T>
    static bool HasComponent() {
        return GetComponent<T>() != nullptr;
    }

private:
    static std::vector<std::unique_ptr<BaseComponent>> components;

};


