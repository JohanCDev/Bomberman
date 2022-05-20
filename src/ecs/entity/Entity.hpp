/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
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
                this->_componentVector.push_back(std::unique_ptr<T>(new T{std::forward<Args>(args)...}));
            }

            bool hasCompoType(ecs::compoType type) {
                for (auto &compo : _componentVector) {
                    if (compo->getType() == type)
                        return (true);
                }
                return (false);
            }

            template<typename T>
            T *getComponent(ecs::compoType type) {
                for (auto &compo : _componentVector) {
                    if (compo->getType() == type) {
                        return (dynamic_cast<T *>(compo.get()));
                    }
                }
                return (nullptr);
            }

            bool isDrawable(ecs::compoType type) {
                if (type == ecs::compoType::CIRCLE || type == ecs::compoType::RECTANGLE) {
                    return (true);
                } else {
                    return (false);
                }
            }

            void draw() {
                for (auto &compo : _componentVector) {
                    if (isDrawable(compo->getType()) == true) {
                        ecs::Drawable *drawableCompo = dynamic_cast<ecs::Drawable *>(compo.get());
                        ecs::Transform *compo = getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
                        drawableCompo->draw(*compo);
                    }
                }
            }
            
        protected:
        private:
            std::vector<std::unique_ptr<IComponent>> _componentVector;
    };
}

#endif /* !ENTITY_HPP_ */
