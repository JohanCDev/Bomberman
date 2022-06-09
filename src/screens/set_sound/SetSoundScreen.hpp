/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetSoundScreen.hpp
*/

#ifndef SETSOUNDSCREEN_HPP_
#define SETSOUNDSCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class SetSoundScreen : public IScreen {
            enum cursorPosition {
                SOUND_0 = 285,
                SOUND_25 = 410,
                SOUND_50 = 535,
                SOUND_75 = 660,
                SOUND_100 = 785,
            };

          public:
            SetSoundScreen();
            ~SetSoundScreen() = default;
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
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !SetFpsScreen_HPP_ */
