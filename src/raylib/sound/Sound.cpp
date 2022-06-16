/**
 * @file Sound.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Sound encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Sound.hpp"

indie::raylib::Sound::Sound(const std::string &fileName) : _volume(1)
{
    _sound = ::LoadSound(fileName.c_str());
}

::Sound indie::raylib::Sound::getSound() const
{
    return _sound;
}

void indie::raylib::Sound::initAudioDevice()
{
    ::InitAudioDevice();
}

::Sound indie::raylib::Sound::load(const char *fileName)
{
    return ::LoadSound(fileName);
}

void indie::raylib::Sound::update(::Sound sound, const void *data, int samplesCount)
{
    ::UpdateSound(sound, data, samplesCount);
}

void indie::raylib::Sound::unload(::Sound sound)
{
    ::UnloadSound(sound);
}

void indie::raylib::Sound::unload()
{
    ::UnloadSound(_sound);
}

void indie::raylib::Sound::play(::Sound sound) {
    ::PlaySound(sound);
}

void indie::raylib::Sound::play()
{
    ::PlaySound(_sound);
}

void indie::raylib::Sound::stop(::Sound sound)
{
    ::StopSound(sound);
}

void indie::raylib::Sound::stop()
{
    ::StopSound(_sound);
}

void indie::raylib::Sound::pause(::Sound sound)
{
    ::PauseSound(sound);
}

void indie::raylib::Sound::pause()
{
    ::PauseSound(_sound);
}

void indie::raylib::Sound::resume(::Sound sound)
{
    ::ResumeSound(sound);
}

void indie::raylib::Sound::resume()
{
    ::ResumeSound(_sound);
}

float indie::raylib::Sound::getVolume() const
{
    return _volume;
}

// void indie::raylib::Sound::setVolume(::Sound sound, float volume)
// {
//     ::SetSoundVolume(sound, volume);
//     _volume = volume;
// }

void indie::raylib::Sound::setVolume(float volume)
{
    ::SetSoundVolume(_sound, volume);
    _volume = volume;
}

void indie::raylib::Sound::setPitch(float pitch)
{
    ::SetSoundPitch(_sound, pitch);
}

void indie::raylib::Sound::setPitch(::Sound sound, float pitch)
{
    ::SetSoundPitch(sound, pitch);
}

bool indie::raylib::Sound::isPlaying(::Sound sound)
{
    return ::IsSoundPlaying(sound);
}

bool indie::raylib::Sound::isPlaying() const
{
    return ::IsSoundPlaying(_sound);
}
