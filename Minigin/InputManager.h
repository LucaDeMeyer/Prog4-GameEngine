#pragma once
#include <map>
#include <utility>
#include <vector>

#include "Singleton.h"

class BaseCommand;

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();

		void AddKeyBinding(int key, int state, BaseCommand* command) {
			keyBindings[key].push_back(std::make_pair(state, command));
		}
	private:

		std::map<int, std::vector<std::pair<int, BaseCommand*>>> keyBindings;
	};

}
