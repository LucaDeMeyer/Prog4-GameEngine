#include "Controller.h"

bool Controller::IsButtonDown(ControllerButton button)
{
    WORD buttonFlags = 0;

    switch (button) {

    case BUTTON_A:
        buttonFlags = XINPUT_GAMEPAD_A;
        break;
    case BUTTON_B:
        buttonFlags = XINPUT_GAMEPAD_B;
        break;
    case BUTTON_X:
        buttonFlags = XINPUT_GAMEPAD_X;
        break;
    case DPAD_DOWN:
        buttonFlags = XINPUT_GAMEPAD_DPAD_DOWN;
        break;
    case DPAD_LEFT:
        buttonFlags = XINPUT_GAMEPAD_DPAD_LEFT;
        break;
    case DPAD_RIGHT:
        buttonFlags = XINPUT_GAMEPAD_DPAD_RIGHT;
        break;
    case DPAD_UP:
        buttonFlags = XINPUT_GAMEPAD_DPAD_UP;
        break;

    default:
        return false;
    }

    return (m_State.Gamepad.wButtons & buttonFlags) != 0;
}

bool Controller::IsConnected()
{
    DWORD result = XInputGetState(m_PlayerIndex, &m_State);
    return result == ERROR_SUCCESS;
}

