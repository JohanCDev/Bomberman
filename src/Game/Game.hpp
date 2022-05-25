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

        protected:
        private:
            Screens _actualScreen;
            size_t _fps;
            std::map<Screens, std::unique_ptr<IScreen> > _screens;
    };
}

#endif /* !GAME_HPP_ */
