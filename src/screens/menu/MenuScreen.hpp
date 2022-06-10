/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <map>
#include <memory>
#include <raylib.h>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../../tools/Tools.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class MenuScreen : public IScreen {
          public:
            enum cursorPosition { NEW_GAME = 0, LOAD_GAME = 1, EXIT = 2 };
            MenuScreen();
            ~MenuScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            void setSize(int where, float height, float width);
            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::map<cursorPosition, float> _positionsCursor;
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
