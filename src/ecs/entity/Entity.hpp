/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include "../component/Component.hpp"
#include <unordered_map>

namespace indie
{
    namespace ecs
    {
        /**
         * @brief Entity base class
         *
         */
        class Entity {
          public:
            /**
             * @brief Construct a new Entity object
             */
            Entity();
            /**
             * @brief Destroy the Entity object
             */
            ~Entity();

            template <typename T, typename... Args>
            /**
             * @brief Add a component to the entity
             *
             * @param args all components to add
             */
            void addComponent(Args... args)
            {
                T *newCompo(new T(std::forward<Args>(args)...));
                this->_componentMap.emplace(typeid(T).name(), newCompo);
            }
            /**
             * @brief Get the Position object of the entity
             */
            void getPosition();
            /**
             * @brief Get the Movement object of the entity
             */
            void getMovement();
            /**
             * @brief Get the CircleRadius object of the entity
             */
            void getCircleRadius();

          protected:
          private:
            std::unordered_map<std::string, std::unique_ptr<IComponent>> _componentMap;
        };
    } // namespace ecs
} // namespace indie

#endif /* !ENTITY_HPP_ */
