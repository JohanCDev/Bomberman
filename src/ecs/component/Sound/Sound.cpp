/**
 * @file Sound.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Sound component source file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Sound.hpp"

indie::ecs::component::Sound::Sound(std::string soundPath, bool play, float volume) : _soundPath(soundPath)
{
    this->_play = play;
    this->_volume = volume;
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

float indie::ecs::component::Sound::getVolume() const
{
    return (this->_volume);
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

void indie::ecs::component::Sound::setVolume(float volume)
{
    this->_volume = volume;
}
