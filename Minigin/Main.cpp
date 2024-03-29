#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "FPSComponent.h"
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");


	
	auto backGround = std::make_shared<dae::GameObject>();
	auto backgroundTransform = new dae::TransformComponent(backGround.get());
	auto backGroundTexture = new dae::TextureComponent(backGround.get());
	auto backgroundRenderer = new dae::RenderComponent(backGround.get());
	backGround->AddComponent(backgroundTransform);
	backGround->AddComponent(backGroundTexture);
	backGround->GetComponent<dae::TextureComponent>()->LoadTexture("backGround.tga");
	backGround->AddComponent(backgroundRenderer);
	scene.Add(backGround);

	auto logo = std::make_shared<dae::GameObject>();
	auto logoTransform = new dae::TransformComponent(logo.get());
	auto logoTexture = new dae::TextureComponent(logo.get());
	auto logoRenderer = new dae::RenderComponent(logo.get());
	logo->AddComponent(logoTransform);
	logo->AddComponent(logoTexture);
	logo->GetComponent<dae::TextureComponent>()->LoadTexture("logo.tga");
	logo->AddComponent(logoRenderer);
	logo->GetComponent<dae::TransformComponent>()->SetPosition(300.0f, 20.0f, 0.0f);
	scene.Add(logo);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	auto fpsCounter = std::make_shared<dae::GameObject>();
	auto fpsTransform = new dae::TransformComponent(fpsCounter.get());
	auto fpsTexture = new dae::TextureComponent(fpsCounter.get());
	auto fpscomp = new dae::FPSComponent(fpsCounter.get());
	auto fpsTextcomp = new dae::TextComponent(std::to_string(fpscomp->GetFps()), font, fpsCounter.get(), fpsTexture);
	
	auto fpsRender = new dae::RenderComponent(fpsCounter.get());
	


	fpsCounter->AddComponent(fpsTransform);
	fpsCounter->AddComponent(fpsTextcomp);
	fpsCounter->AddComponent(fpscomp);
	fpsCounter->AddComponent(fpsTexture);
	fpsCounter->AddComponent(fpsRender);
	//fpsCounter->AddComponent(fpscomp);
	
	
	fpsCounter->GetComponent<dae::TransformComponent>()->SetPosition(100.f, 50.f, 0.f);
	scene.Add(fpsCounter);

	
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}