#include "InputHandler.h"
#include "CommandListener.h"
#include "Config.h"

namespace BB {

  InputHandler::InputHandler(){
    p1GamepadID = 0;
  }

  InputHandler::~InputHandler(){
  }

  void InputHandler::handleInput(CommandListener &listener){
    bool moving = false;

    //Up/down
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_FACE_UP)){
      listener.goUp();
      moving = true;
    }else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_W) || IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
      listener.goDown();
      moving = true;
    }

    // Left/right
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) || IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
      listener.goRight();
      moving = true;
    }else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) || IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
      listener.goLeft();
      moving = true;
    }

    if(!moving){
      listener.goNowhere();
    }

    // Select, push, pull, etc.
    if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) ||
       IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_TRIGGER_1) ||
       IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_RIGHT_TRIGGER_1) ||
       IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_THUMB)){
      listener.doInteractWith();
    }
  }
  
}
