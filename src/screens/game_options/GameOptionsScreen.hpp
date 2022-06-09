/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** GameOptionsScreen.hpp
*/

#ifndef GAME_OPTIONS_SCREEN_HPP_
#define GAME_OPTIONS_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class GameOptionsScreen : public IScreen {
          public:
            enum cursorPosition {
                RESUME = 200,
                MENU = 325,
                SAVE = 450,
                MUSIC = 575,
                SOUND = 700,
                FPS = 825,
                EXIT = 950
            };
            GameOptionsScreen();
            ~GameOptionsScreen() = default;
            void init() override;
            void draw() override;
            void update(float delta) override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            bool getIsGameOptionsCalling() const;
            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            int _cursorPosition;

            bool _isGameOptionsCalling;
        };
    } // namespace menu
} // namespace indie

#endif /* !GAME_OPTIONS_SCREEN_HPP_ */