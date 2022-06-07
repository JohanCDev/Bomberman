/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** PreMenuScreen.cpp
*/

#ifndef PRE_MENU_SCREEN_HPP_
#define PRE_MENU_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"

namespace indie
{
    namespace menu
    {
        class PreMenuScreen : public IScreen {
          public:
            PreMenuScreen();
            ~PreMenuScreen() = default;
            void draw() override;
            void update(float delta) override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
        };
    } // namespace menu
} // namespace indie

#endif /* !PRE_MENU_SCREEN_HPP_ */