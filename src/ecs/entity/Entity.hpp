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
#include <vector>
#include "../component/Drawable2D/Drawable2D.hpp"
#include "../component/Drawable3D/Drawable3D.hpp"
#include "../component/IComponent.hpp"
#include "../component/Transform/Transform.hpp"

namespace indie
{
    namespace ecs
    {
        namespace entity
        {
            class Entity {
              public:
                /**
                 * @brief Create new entity.
                 */
                Entity();

                /**
                 * @brief Destroy entity.
                 */
                ~Entity();

                /**
                 * @brief Add component to entity.
                 *
                 * @param T the component to add.
                 * @param args the necessary params to create the component.
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
                 * @return a boolean at true if the component is present.
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
                 * @brief Get a component of the given type.
                 *
                 * @param T the type of component to get.
                 * @param type the compoType value of component to get.
                 *
                 * @return a pointer to the component asked.
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

                void setAlive(bool alive)
                {
                    this->_alive = alive;
                }

                bool getAlive(void)
                {
                    return (this->_alive);
                }

              protected:
              private:
                std::vector<std::unique_ptr<indie::ecs::component::IComponent>> _componentVector;
                bool _alive;
            };
        } // namespace entity
    }     // namespace ecs
} // namespace indie

#endif /* !ENTITY_HPP_ */
