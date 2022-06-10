/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** GameOptionsScreen.hpp
*/

#ifndef GAME_OPTIONS_SCREEN_HPP_
#define GAME_OPTIONS_SCREEN_HPP_

#include <map>
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
                RESUME = 0,
                MENU = 1,
                SAVE = 2,
                MUSIC = 3,
                SOUND = 4,
                FPS = 5,
                EXIT = 6,
            };
            GameOptionsScreen();
            ~GameOptionsScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            void setSize(int where, float height, float width);
            bool getIsGameOptionsCalling() const;
            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::map<cursorPosition, float> _positionsCursor;
            int _cursorPosition;

            bool _isGameOptionsCalling;
        };
    } // namespace menu
} // namespace indie

#endif /* !GAME_OPTIONS_SCREEN_HPP_ */