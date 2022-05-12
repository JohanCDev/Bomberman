/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "ecs/entity/Entity.hpp"
#include "ecs/component/Component.hpp"
#include <iostream>

int main(void)
{
    ecs::Entity entity;

    entity.addComponent<ecs::Position>(100.0, 100.0);
    entity.addComponent<ecs::Movement>(30.0, 30.0);
    entity.getPosition();
    entity.getMovement();
    return (0);
}