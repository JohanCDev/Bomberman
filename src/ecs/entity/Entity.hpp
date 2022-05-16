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
#include <memory>

namespace ecs {
    class Entity {
        public:
            Entity();
            ~Entity();

            template<typename T, typename... Args>
            void addComponent(Args... args) {
                T *newCompo(new T(std::forward<Args>(args)...));
                this->_componentMap.emplace(typeid(T).name(), newCompo);
            }
            void getPosition();
            void getMovement();
            void getCircleRadius();

        protected:
        private:
            std::unordered_map<std::string, std::unique_ptr<IComponent>> _componentMap;
    };
}

#endif /* !ENTITY_HPP_ */
