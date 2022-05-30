/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <cstddef>
#include <map>
#include <memory>
#include "../screens/IScreen.hpp"
#include "../screens/game/GameScreen.hpp"
#include "../screens/menu/MenuScreen.hpp"
#include "../screens/options/OptionsScreen.hpp"
#include "events.hpp"

namespace indie
{
    class Game {
      public:
        enum class Screens { Game, Menu, Options, ExitScreen, Count };
        Game(size_t baseFps = 60);
        ~Game();
        void run();
        void draw();
        int handleEvent();
        void update(float delta);
        bool processEvents();

        void setActualScreen(Screens newScreen);

      protected:
      private:
        Screens _actualScreen;
        size_t _fps;
        indie::menu::MenuScreen *_menu;
        indie::menu::GameScreen *_game;
        indie::menu::OptionsScreen *_options;
        indie::Event _event;
    };
} // namespace indie

#endif /* !GAME_HPP_ */
