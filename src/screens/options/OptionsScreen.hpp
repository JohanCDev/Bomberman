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
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        enum cursorPositionOptions { FPS = 410, MENU = 510, EXIT = 610 };

        class OptionsScreen : public IScreen {
          public:
            OptionsScreen();
            ~OptionsScreen() = default;
            void draw() override;
            void update(float delta) override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !OPTIONSSCREEN_HPP_ */