/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#include "Sound.hpp"

indie::ecs::system::Sound::Sound()
{
}

indie::ecs::system::Sound::~Sound()
{
}

indie::ecs::system::SystemType indie::ecs::system::Sound::getSystemType() const
{
    return (indie::ecs::system::SystemType::SOUNDSYSTEM);
}

void indie::ecs::system::Sound::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::SOUND)) {
            auto soundComponent = entity->getComponent<indie::ecs::component::Sound>(indie::ecs::component::SOUND);
            if (soundComponent->getPlay() == true) {
                indie::raylib::Sound sound(soundComponent->getSoundPath());
                sound.setVolume(1.0);
                sound.play();
            }
        }
    }
}