/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** OptionsScreen.hpp
*/

#ifndef OptionsSCREEN_HPP_
#define OptionsSCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"

namespace indie
{
    namespace menu
    {
        enum cursorPositionOptions { RESUME = 510, MENU = 610, EXIT = 710 };

        class OptionsScreen : public IScreen {
          public:
            OptionsScreen();
            ~OptionsScreen() = default;
            void draw() override;
            void update(float delta) override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<ecs::Entity> entity) override;

            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<ecs::Entity>> _entities;
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !OPTIONSSCREEN_HPP_ */