/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#ifndef Window_HPP_
#define Window_HPP_

#include "Raylib.hpp"

namespace Raylib {
  class Window {
    public:
      Window() = default;
      ~Window() = default;

      // Setup function
      static void initWindow(size_t width = 1920, size_t heigth = 1080, const std::string title = "Window",
          bool resizable = true, int baseFps = 60);
      static void destroyWindow();

      // Window function
      static void beginDrawing();
      static void endDrawing();
      static void clearBackground();
      static bool windowShouldClose();
  };
}

#endif /* !Window_HPP_ */
