/**
 * @file Explodable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Explodable.hpp"
#include <cmath>

indie::ecs::system::Explodable::Explodable()
{
}

indie::ecs::system::Explodable::~Explodable()
{
}

float indie::ecs::system::Explodable::getValue(float position, float index, char operand)
{
    while (1) {
        float test = std::fmod(static_cast<float>(position), 0.5f);
        if (test >= 0.01 || test <= -0.01) {
            if (operand == '+') {
                position += 0.01f;
            } else {
                position -= 0.01f;
            }
        } else {
            break;
        }
    }
    return (position);
}

std::map<size_t, indie::ecs::entity::Entity *> indie::ecs::system::Explodable::getEntityByPosition(
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities, float x, float y)
{
    size_t count = 0;
    std::map<size_t, indie::ecs::entity::Entity *> map;
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::TRANSFORM) == true
            && entity->hasCompoType(indie::ecs::component::COLLECTABLE) == false) {
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            if (transformCompo->getX() == x && transformCompo->getY() == y) {
                map.emplace(count, entity.get());
                return (map);
            }
        }
        count++;
    }
    return (map);
}

void indie::ecs::system::Explodable::destroyBoxes(std::vector<int> &compoToRemove,
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
    indie::ecs::component::Explodable *explodableCompo, indie::ecs::component::Transform *bombTransformCompo)
{
    float x_position = 0.0;
    float x_position2 = 0.0;
    float new_x_position = bombTransformCompo->getX();
    if (std::fmod(bombTransformCompo->getX(), 0.5f) != 0.0) {
        x_position = getValue(bombTransformCompo->getX(), 0.5, '+');
        x_position2 = getValue(bombTransformCompo->getX(), -0.5, '-');
        float f;
        float f2;
        f2 = std::modf(x_position, &f);
        if (std::abs(f2) <= 0.1) {
            x_position = x_position - f2;
        }
        f2 = std::modf(x_position2, &f);
        if (std::abs(f2) <= 0.1) {
            x_position2 = x_position2 - f2;
        }
        f2 = std::modf(x_position, &f);
        if (std::abs(f2) >= 0.48 && std::abs(f2) <= 0.51) {
            f2 *= 10.0;
            f = std::modf(f2, &f2);
            x_position = x_position - (f / 10.0);
        }
        f2 = std::modf(x_position2, &f);
        if (std::abs(f2) >= 0.48 && std::abs(f2) <= 0.51) {
            f2 *= 10.0;
            f = std::modf(f2, &f2);
            x_position2 = x_position2 - (f / 10.0);
        }
        if ((std::abs(bombTransformCompo->getX() - x_position))
            < (std::abs(bombTransformCompo->getX() - x_position2))) {
            new_x_position = x_position;
        } else {
            new_x_position = x_position2;
        }
    }
    float y_position = 0.0;
    float y_position2 = 0.0;
    float new_y_position = bombTransformCompo->getY();
    if (std::fmod(bombTransformCompo->getY(), 0.5f) != 0.0) {
        y_position = getValue(bombTransformCompo->getY(), 0.5, '+');
        y_position2 = getValue(bombTransformCompo->getY(), -0.5, '-');
        float f;
        float f2;
        f2 = std::modf(y_position, &f);
        if (std::abs(f2) <= 0.1) {
            y_position = y_position - f2;
        }
        f2 = std::modf(y_position2, &f);
        if (std::abs(f2) <= 0.1) {
            y_position2 = y_position2 - f2;
        }
        f2 = std::modf(y_position, &f);
        if (std::abs(f2) >= 0.49 && std::abs(f2) <= 0.51) {
            f2 *= 10.0;
            f = std::modf(f2, &f2);
            y_position = y_position - (f / 10.0);
        }
        f2 = std::modf(y_position2, &f);
        if (std::abs(f2) >= 0.49 && std::abs(f2) <= 0.51) {
            f2 *= 10.0;
            f = std::modf(f2, &f2);
            y_position2 = y_position2 - (f / 10.0);
        }
        if ((std::abs(bombTransformCompo->getY() - y_position))
            < (std::abs(bombTransformCompo->getY() - y_position2))) {
            new_y_position = y_position;
        } else {
            new_y_position = y_position2;
        }
    }
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange(); i += 0.5, counter += 0.5) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        if (i == 0) {
            entityMap = getEntityByPosition(entities, new_x_position - 0.5f, new_y_position);
        } else {
            entityMap = getEntityByPosition(entities, (new_x_position - counter - 0.5f), new_y_position);
        }
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            if ((transformCompo->getX() >= new_x_position + (-i - 0.5) && transformCompo->getX() <= new_x_position)
                && transformCompo->getY() == new_y_position) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    size_t count = 0;
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index - count);
        count++;
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange(); i += 0.5, counter += 0.5) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        if (i == 0) {
            entityMap = getEntityByPosition(entities, new_x_position + 0.5f, new_y_position);
        } else {
            entityMap = getEntityByPosition(entities, (new_x_position + counter + 0.5f), new_y_position);
        }
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            std::cout << "transformCompo " << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
            if ((transformCompo->getX() <= new_x_position + (i + 0.5) && transformCompo->getX() >= new_x_position)
                && transformCompo->getY() == new_y_position) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    count = 0;
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index - count);
        count++;
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange(); i += 0.5, counter += 0.5) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        if (i == 0) {
            entityMap = getEntityByPosition(entities, new_x_position, new_y_position + 0.5f);
        } else {
            entityMap = getEntityByPosition(entities, new_x_position, new_y_position + counter + 0.5f);
        }
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            // std::cout << "transform compo " << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
            // std::cout << "bomb pos " << new_x_position << " " << new_y_position << std::endl;
            if ((transformCompo->getY() <= new_y_position + (i + 0.5) && transformCompo->getY() >= new_y_position)
                && transformCompo->getX() == new_x_position) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                    // std::cout << index << std::endl;
                } else {
                    break;
                }
            }
        }
    }
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index);
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange(); i += 0.5, counter += 0.5) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        if (i == 0) {
            entityMap = getEntityByPosition(entities, new_x_position, new_y_position - 0.5f);
        } else {
            entityMap = getEntityByPosition(entities, new_x_position, new_y_position - counter - 0.5f);
        }
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            if ((transformCompo->getY() >= new_y_position + (-i - 0.5) && transformCompo->getY() <= new_y_position)
                && (transformCompo->getX() >= new_x_position)) {
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    count = 0;
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index - count);
        count++;
    }
    compoToRemove.clear();
}

void indie::ecs::system::Explodable::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    std::vector<int> compoToRemove;
    std::vector<indie::ecs::entity::Entity *> bombVector;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            bombVector.push_back(entity.get());
        }
    }
    for (auto &entity : bombVector) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExplode() == true) {
                    explodableCompo->setExploded(true);
                    destroyBoxes(compoToRemove, entities, explodableCompo,
                        entity->getComponent<ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM));
                } else {
                    auto t_now = std::chrono::system_clock::now();
                    std::chrono::seconds elapsed =
                        std::chrono::duration_cast<std::chrono::seconds>(t_now - explodableCompo->getTStart());
                    if (explodableCompo->getSeconds() <= elapsed) {
                        explodableCompo->setExplode(true);
                    }
                }
            }
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}