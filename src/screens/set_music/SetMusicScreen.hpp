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
                MUSIC = 210,
                MUSIC_0 = 310,
                MUSIC_25 = 410,
                MUSIC_50 = 510,
                MUSIC_75 = 610,
                MUSIC_100 = 710,
                OPTIONS = 810
            };

          public:
            SetMusicScreen();
            ~SetMusicScreen() = default;
            void init() override;
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

#endif /* !SetFpsScreen_HPP_ */
