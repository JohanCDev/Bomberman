/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <unordered_map>
#include <string>
#include <typeinfo>
#include "../component/Component.hpp"
#include <iostream>

namespace ecs {
    class Entity {
        public:
            Entity();
            ~Entity();

            template<typename T, typename... Args>
            void addComponent(Args... args) {
                T newCompo(std::forward<Args>(args)...);
                this->_componentMap.emplace(typeid(T).name(), newCompo);
            }
            void getPosition();
            void getMovement();

        protected:
        private:
            std::unordered_map<std::string, IComponent> _componentMap;
    };
}

#endif /* !ENTITY_HPP_ */
