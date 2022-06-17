/**
 * @file Entity.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Entity header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../component/Alive/Alive.hpp"
#include "../component/Collectable/Collectable.hpp"
#include "../component/Collide/Collide.hpp"
#include "../component/Destroyable/Destroyable.hpp"
#include "../component/Drawable2D/Drawable2D.hpp"
#include "../component/Drawable3D/Drawable3D.hpp"
#include "../component/Explodable/Explodable.hpp"
#include "../component/IComponent.hpp"
#include "../component/Inventory/Inventory.hpp"
#include "../component/Object/Object.hpp"
#include "../component/Sound/Sound.hpp"
#include "../component/Transform/Transform.hpp"

namespace indie
{
    namespace ecs
    {
        namespace entity
        {
            /**
             * @brief Entity Type for entity object creation
             *
             */
            enum entityType { PLAYER_1, PLAYER_2, PLAYER_3, PLAYER_4, WALL, BOXES, TEXT, BOMB, UNKNOWN };
            /// @brief Entity class
            class Entity {
              public:
                /**
                 * @brief Create new entity.
                 *
                 * @param type Entity type
                 */
                Entity(entityType type);
                /**
                 * @brief Construct a new Entity object
                 *
                 */
                Entity();
                /**
                 * @brief Destroy entity.
                 */
                ~Entity();
                /**
                 * @brief Add component to entity
                 *
                 * @tparam T the component to add
                 * @tparam Args The necessary params to create the component
                 * @param args The necessary params to create the component
                 */
                template <typename T, typename... Args> void addComponent(Args... args)
                {
                    this->_componentVector.push_back(std::unique_ptr<T>(new T{std::forward<Args>(args)...}));
                }

                /**
                 * @brief Check if the entity have a component of the given type.
                 *
                 * @param type the compoType value to check.
                 *
                 * @return true The component is present
                 * @return false The component isn't present
                 */
                bool hasCompoType(indie::ecs::component::compoType type)
                {
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == type)
                            return (true);
                    }
                    return (false);
                }
                /**
                 * @brief Get the Drawable Vector
                 *
                 * @return std::vector<indie::ecs::component::Drawable2D *> Vector of Drawable2D component
                 */
                std::vector<indie::ecs::component::Drawable2D *> getDrawableVector() const
                {
                    std::vector<indie::ecs::component::Drawable2D *> vector;
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == indie::ecs::component::compoType::DRAWABLE2D) {
                            vector.push_back(dynamic_cast<indie::ecs::component::Drawable2D *>(compo.get()));
                        }
                    }
                    return (vector);
                }
                /**
                 * @brief Get the Component of the given type
                 *
                 * @tparam T The type of component to get
                 * @param type The compoType value of the component to get
                 *
                 * @return T* Pointer to the wanted component
                 */
                template <typename T> T *getComponent(indie::ecs::component::compoType type)
                {
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == type) {
                            return (dynamic_cast<T *>(compo.get()));
                        }
                    }
                    return (nullptr);
                }
                /**
                 * @brief Get the Entity Type
                 *
                 * @return indie::ecs::entity::entityType The entity type
                 */
                indie::ecs::entity::entityType getEntityType() const;

              private:
                /**
                 * @brief Vector of component
                 *
                 */
                std::vector<std::unique_ptr<indie::ecs::component::IComponent>> _componentVector;
                /**
                 * @brief Entity type object
                 *
                 */
                entity::entityType _type;
            };
        } // namespace entity
    }     // namespace ecs
} // namespace indie

#endif /* !ENTITY_HPP_ */
