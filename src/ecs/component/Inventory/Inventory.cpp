/*
** EPITECH PROJECT, 2022
** Inventory
** File description:
** Inventory
*/

#include "Inventory.hpp"

indie::ecs::component::Inventory::Inventory()
{
    this->_bombUp = false;
    this->_fireUp = false;
    this->_speedUp = false;
    this->_wallPass = false;
}

indie::ecs::component::Inventory::~Inventory()
{
}

indie::ecs::component::compoType indie::ecs::component::Inventory::getType() const
{
    return (indie::ecs::component::compoType::INVENTORY);
}

bool indie::ecs::component::Inventory::getBombUp() const
{
    return (this->_bombUp);
}

bool indie::ecs::component::Inventory::getFireUp() const
{
    return (this->_fireUp);
}

bool indie::ecs::component::Inventory::getSpeedUp() const
{
    return (this->_speedUp);
}

bool indie::ecs::component::Inventory::getWallPass() const
{
    return (this->_wallPass);
}

void indie::ecs::component::Inventory::setBombUp(bool bonus)
{
    this->_bombUp = bonus;
}

void indie::ecs::component::Inventory::setFireUp(bool bonus)
{
    this->_fireUp = bonus;
}

void indie::ecs::component::Inventory::setSpeedUp(bool bonus)
{
    this->_speedUp = bonus;
}

void indie::ecs::component::Inventory::setWallPass(bool bonus)
{
    this->_wallPass = bonus;
}