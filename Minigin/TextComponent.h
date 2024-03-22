#pragma once
#include <string>
#include <memory>
#include <windows.h>

#include "BaseComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"

namespace dae
{
	class TextureComponent;
}

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent  : public BaseComponent
	{
	public:
		

		TextComponent(const std::string& text, std::shared_ptr<Font> font,GameObject* owner,TextureComponent* textureComp);~TextComponent() override = default;

		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

		void Update(float deltaTime) override;
		void SetText(const std::string& text);

	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		TextureComponent* m_TextureComp;
	};
}
