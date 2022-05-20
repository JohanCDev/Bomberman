/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "Entity.hpp"
#include "Component.hpp"

namespace ecs {

    class ISystem {
        public:
            virtual ~ISystem() = default;

            virtual void update(std::vector<std::unique_ptr<ecs::Entity>> &entities) = 0;

        private:
    };

    class MovementSystem : public ISystem {
        
        public:
            MovementSystem() {}
            ~MovementSystem() {}

            void update(std::vector<std::unique_ptr<ecs::Entity>> &entities) override {
                for (auto &entity: entities) {
                    if (entity->getAlive() == true && entity->hasCompoType(ecs::compoType::TRANSFORM)) {
                        ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
                        transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
                        transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
                    }
                }
            }
        private:
    };

}

#endif /* !SYSTEM_HPP_ */
