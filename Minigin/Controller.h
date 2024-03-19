#pragma once

#include <Windows.h>
#include <XInput.h>
enum ControllerButton {
    BUTTON_A,
    BUTTON_B,
    BUTTON_X,
    BUTTON_Y,
    BUTTON_LEFT_SHOULDER,
    BUTTON_RIGHT_SHOULDER,
    BUTTON_LEFT_TRIGGER,
    BUTTON_RIGHT_TRIGGER,
    BUTTON_BACK,
    BUTTON_START,
    BUTTON_LEFT_THUMB,
    BUTTON_RIGHT_THUMB,
    DPAD_UP,
    DPAD_DOWN,
    DPAD_LEFT,
    DPAD_RIGHT
};

class Controller
{

public:

    Controller(int index) :m_PlayerIndex(index){}


    bool IsConnected();
    bool IsButtonDown(ControllerButton button);

private:
    int m_PlayerIndex;
    XINPUT_STATE m_State;

};

