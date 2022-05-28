/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** World
*/

#include "World.hpp"

ecs::World::World()
{
}

ecs::World::~World()
{
}

void ecs::World::addEntity(std::unique_ptr<ecs::Entity> entity) {
    this->entities.push_back(std::move(entity));
}

void ecs::World::createSystem() {
    systems.push_back(std::make_unique<ecs::MovementSystem>());
}