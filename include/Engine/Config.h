#pragma once
#include "raylib.h"
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <cstddef>
#include <list>

// #define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WIDTH 802
#define HEIGHT 502

#define TITLE_FONT_SIZE 160
#define SUB_TITLE_FONT_SIZE 100
#define TITLE_FONT_SPACING 10.0f
#define MENU_FONT_SIZE 40

#define BUTTON_WIDTH 280
#define BUTTON_HEIGHT 70
#define BUTTON_SPACING (BUTTON_HEIGHT + 10)

inline void showErrorAndExit(const char *errMsg){
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(errMsg, 20, 20, 20, RED);
    EndDrawing();
  }

  exit(EXIT_FAILURE);
}
