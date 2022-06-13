/**
 * @file SetMusicScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change the volume of the music
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SETMUSICSCREEN_HPP_
#define SETMUSICSCREEN_HPP_

#include <map>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class SetMusicScreen : public IScreen {
            enum cursorPosition {
                MUSIC_0 = 0,
                MUSIC_25 = 1,
                MUSIC_50 = 2,
                MUSIC_75 = 3,
                MUSIC_100 = 4,
            };

          public:
            SetMusicScreen();
            ~SetMusicScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::map<cursorPosition, float> _positionsCursor;

            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !SetFpsScreen_HPP_ */
