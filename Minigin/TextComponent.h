#pragma once
#include <string>
#include <memory>
#include <windows.h>

#include "BaseComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"


namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent  : public BaseComponent
	{
	public:
		

		TextComponent(const std::string& text, std::shared_ptr<Font> font,GameObject* owner);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

		void Update();
		void SetText(const std::string& text);

		std::string GetName() const override;
	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
