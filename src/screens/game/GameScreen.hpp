/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#ifndef GAMESCREEN_HPP_
#define GAMESCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"

namespace indie
{
    namespace menu
    {
        class GameScreen : public IScreen {
          public:
            GameScreen();
            ~GameScreen() = default;
            void draw() override;
            void update(float delta) override;
            bool handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<ecs::Entity> entity) override;

          private:
            std::vector<std::unique_ptr<ecs::Entity>> _entities;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
