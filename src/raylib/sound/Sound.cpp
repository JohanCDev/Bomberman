/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#include "Sound.hpp"

indie::raylib::Sound::Sound(const std::string& fileName) {
    _sound = ::LoadSound(fileName.c_str());
}

indie::raylib::Sound::~Sound() {
    ::UnloadSound(_sound);
}

void indie::raylib::Sound::play() {
    ::PlaySound(_sound);
}

void indie::raylib::Sound::stop() {
    ::StopSound(_sound);
}

void indie::raylib::Sound::pause() {
    ::PauseSound(_sound);
}

void indie::raylib::Sound::resume() {
    ::ResumeSound(_sound);
}

void indie::raylib::Sound::setVolume(float volume) {
    ::SetSoundVolume(_sound, volume);
}

void indie::raylib::Sound::setPitch(float pitch) {
    ::SetSoundPitch(_sound, pitch);
}

bool indie::raylib::Sound::isPlaying() const {
    return ::IsSoundPlaying(_sound);
}
