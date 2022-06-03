/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#include "Sound.hpp"

indie::ecs::component::Sound::Sound(std::string soundPath, bool play) : _soundPath(soundPath)
{
    this->_play = play;
}

indie::ecs::component::Sound::~Sound()
{
}

indie::ecs::component::compoType indie::ecs::component::Sound::getType() const
{
    return (indie::ecs::component::compoType::SOUND);
}

std::string indie::ecs::component::Sound::getSoundPath() const
{
    return (this->_soundPath);
}

/*indie::raylib::Sound indie::ecs::component::Sound::getSound() const
{
    return (this->_sound);
}*/

bool indie::ecs::component::Sound::getPlay() const
{
    return (this->_play);
}

void indie::ecs::component::Sound::setSoundPath(std::string soundPath)
{
    this->_soundPath = soundPath;
}

/*void indie::ecs::component::Sound::setSound(std::string soundPath)
{
    this->_soundPath = soundPath;
    this->_sound = indie::raylib::Sound(soundPath.c_str());
}*/

void indie::ecs::component::Sound::setPlay(bool play)
{
    this->_play = play;
}