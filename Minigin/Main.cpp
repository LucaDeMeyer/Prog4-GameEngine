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

	/*auto go = std::make_shared<dae::GameObject>();
	go->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	scene.Add(go);*/

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	//auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	//to->SetPosition(300, 20);
	//scene.Add(to);

	auto fpscounter = std::make_shared<dae::GameObject>();
	auto fpsComponent = new FPSComponent(*fpscounter);
	auto fpsRenderComp = new RenderComponent(*fpscounter);
	auto fpsTextComp = new dae::TextComponent(std::to_string(fpsComponent->GetFps()),font,*fpscounter);
	auto fpsTransform = new dae::TransformComponent(*fpscounter);
	auto fpsTextureComp = new TextureComponent(*fpscounter, "background.tga");

	fpscounter->AddComponent(fpsComponent);
	fpscounter->AddComponent(fpsRenderComp);
	fpscounter->AddComponent(fpsTextComp);
	fpscounter->AddComponent(fpsTransform);
	fpscounter->AddComponent(fpsTextureComp);
	
	fpsTransform->SetPosition(216, 180,0);
	scene.Add(fpscounter);

	
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}