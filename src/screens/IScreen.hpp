/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** IScreen
*/

#ifndef ISCREEN_HPP_
#define ISCREEN_HPP_

#include <memory>
#include "../ecs/entity/Entity.hpp"
#include "../ecs/system/ISystem.hpp"
#include "events.hpp"

namespace indie
{
    class IScreen {
      public:
        virtual ~IScreen() = default;
        virtual void init() = 0;
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual int handleEvent(indie::Event &event) = 0;
        virtual void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) = 0;
        virtual void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) = 0;

      protected:
      private:
    };
} // namespace indie

#endif /* !ISCREEN_HPP_ */
