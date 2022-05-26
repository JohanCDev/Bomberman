/*
** EPITECH PROJECT, 2022
** World
** File description:
** World
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <memory>
#include <vector>
#include "System.hpp"
#include "Entity.hpp"

namespace ecs {
    class World {
        public:
            World();
            ~World();
    
            void addEntity(std::unique_ptr<ecs::Entity> entity);

            void createSystem();
    
            std::vector<std::unique_ptr<ecs::Entity>> entities;
            std::vector<std::unique_ptr<ecs::ISystem>> systems;

        protected:
        private:
    };
}

#endif /* !WORLD_HPP_ */
