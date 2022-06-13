/**
 * @file SetSoundScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the options of the game
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
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

            bool getIsGameOptionsCalling() const;
            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::map<int, float> _positionsCursor;
            int _cursorPosition;

            bool _isGameOptionsCalling;
        };
    } // namespace menu
} // namespace indie

#endif /* !GAME_OPTIONS_SCREEN_HPP_ */