/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#include "Sound.hpp"
#include <string>
#include <iostream>

Raylib::Sound::Sound(const std::string& fileName) {
    ::LoadSound(fileName.c_str());
}

Raylib::Sound::~Sound() {
    ::UnloadSound(*_sound);
}

Raylib::Sound &Raylib::Sound::play() {
    ::PlaySound(*_sound);
    return *this;
}

Raylib::Sound &Raylib::Sound::stop() {
    ::StopSound(*_sound);
    return *this;
}

Raylib::Sound &Raylib::Sound::pause() {
    ::PauseSound(*_sound);
    return *this;
}

Raylib::Sound &Raylib::Sound::resume() {
    ::ResumeSound(*_sound);
    return *this;
}

Raylib::Sound &Raylib::Sound::setVolume(float volume) {
    ::SetSoundVolume(*_sound, volume);
    return *this;
}

Raylib::Sound &Raylib::Sound::setPitch(float pitch) {
    ::SetSoundPitch(*_sound, pitch);
    return *this;
}

bool Raylib::Sound::isPlaying() const {
    return ::IsSoundPlaying(*_sound);
}
