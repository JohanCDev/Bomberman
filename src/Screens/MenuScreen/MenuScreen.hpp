/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"

namespace indie
{
    namespace menu
    {
        class MenuScreen : public IScreen {
          public:
            MenuScreen() = default;
            ~MenuScreen() = default;
            void CreateMenuEntities();
            void draw() override;
            void update(float delta) override;
            void handleEvent(indie::Event &event) override;

          private:
            std::vector<ecs::Entity> _entities;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
