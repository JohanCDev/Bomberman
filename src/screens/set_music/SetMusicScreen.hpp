/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetMusicScreen.hpp
*/

#ifndef SETMUSICSCREEN_HPP_
#define SETMUSICSCREEN_HPP_

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
                MUSIC_0 = 285,
                MUSIC_25 = 410,
                MUSIC_50 = 535,
                MUSIC_75 = 660,
                MUSIC_100 = 785,
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
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !SetFpsScreen_HPP_ */
