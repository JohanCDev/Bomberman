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
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "../screens/IScreen.hpp"
#include "../screens/game/GameScreen.hpp"
#include "../screens/menu/MenuScreen.hpp"
#include "../screens/options/OptionsScreen.hpp"
#include "events.hpp"
#include "../screens/pre_menu/PreMenuScreen.hpp"
#include "../screens/set_fps/SetFpsScreen.hpp"
#include "../screens/set_sound/SetSoundScreen.hpp"

namespace indie
{
    class Game {
      public:
        enum class Screens { Game, Menu, Options, PreMenu, SetFps, SetSound, ExitScreen, Count };
        Game(size_t baseFps = 60);
        ~Game();
        void run();
        void draw();
        int handleEvent();
        void update(float delta);
        bool processEvents();

        void handleScreensSwap(int ret);
        void reinitGame();
        void setActualScreen(Screens newScreen);

      protected:
      private:
        Screens _actualScreen;
        size_t _fps;
        indie::menu::MenuScreen *_menu;
        indie::menu::GameScreen *_game;
        indie::menu::OptionsScreen *_options;
        indie::menu::PreMenuScreen *_premenu;
        indie::menu::SetFpsScreen *_setFps;
        indie::menu::SetSoundScreen *_setSound;
        indie::Event _event;
    };
} // namespace indie

#endif /* !GAME_HPP_ */
