/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#include "Sound.hpp"
#include <string>
#include <iostream>

raylib::Sound::Sound(const std::string& fileName) {
    ::LoadSound(fileName.c_str());
}

raylib::Sound::~Sound() {
    ::UnloadSound(*_sound);
}

raylib::Sound &raylib::Sound::play() {
    ::PlaySound(*_sound);
    return *this;
}

raylib::Sound &raylib::Sound::stop() {
    ::StopSound(*_sound);
    return *this;
}

raylib::Sound &raylib::Sound::pause() {
    ::PauseSound(*_sound);
    return *this;
}

raylib::Sound &raylib::Sound::resume() {
    ::ResumeSound(*_sound);
    return *this;
}

raylib::Sound &raylib::Sound::setVolume(float volume) {
    ::SetSoundVolume(*_sound, volume);
    return *this;
}

raylib::Sound &raylib::Sound::setPitch(float pitch) {
    ::SetSoundPitch(*_sound, pitch);
    return *this;
}

bool raylib::Sound::isPlaying() const {
    return ::IsSoundPlaying(*_sound);
}
