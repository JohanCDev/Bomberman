/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** EndScreen.hpp
*/

#ifndef END_SCREEN_HPP_
#define END_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class EndScreen : public IScreen {
          public:
            EndScreen();
            ~EndScreen() = default;
            void init() override;
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

#endif /* !END_SCREEN_HPP_ */