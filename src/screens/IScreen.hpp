/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** IScreen
*/

#ifndef ISCREEN_HPP_
#define ISCREEN_HPP_

#include "events.hpp"
#include "../ecs/entity/Entity.hpp"
#include <memory>

namespace indie
{
    class IScreen {
      public:
        virtual ~IScreen() = default;
        virtual void draw() = 0;
        virtual void update(float delta) = 0;
        virtual void handleEvent(indie::Event &event) = 0;
        virtual void addEntity(std::unique_ptr<ecs::Entity> entity) = 0;

      protected:
      private:
    };
} // namespace indie

#endif /* !ISCREEN_HPP_ */
