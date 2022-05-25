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
#include "../Screens/IScreen.hpp"
#include "../Screens/MenuScreen/MenuScreen.hpp"
#include "../Screens/GameScreen/GameScreen.hpp"

namespace indie {
    class Game {
        public:
            enum class Screens {
                Game,
                Menu,
                Pause,
                ExitScreen,
                Count
            };
            Game(size_t baseFps = 60);
            ~Game();
            void run();
            void draw();
            void update(float delta);
            bool processEvents();

            void setActualScreen(Screens newScreen);

        protected:
        private:
            Screens _actualScreen;
            size_t _fps;
            indie::menu::MenuScreen *_menu;
            indie::menu::GameScreen *_game;
    };
}

#endif /* !GAME_HPP_ */
