/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"

namespace indie
{
    namespace menu
    {
        enum cursorPosition { NEW_GAME = 510, LOAD_GAME = 610, OPTIONS = 710, QUIT = 810 };

        class MenuScreen : public IScreen {
          public:
            MenuScreen();
            ~MenuScreen() = default;
            void draw() override;
            void update(float delta) override;
            bool handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<ecs::Entity> entity) override;

            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<ecs::Entity>> _entities;
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
