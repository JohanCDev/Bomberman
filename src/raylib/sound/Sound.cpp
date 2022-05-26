/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#include "Sound.hpp"
#include <string>
#include <iostream>

indie::raylib::Sound::Sound(const std::string& fileName) {
    ::LoadSound(fileName.c_str());
}

indie::raylib::Sound::~Sound() {
    ::UnloadSound(*_sound);
}

indie::raylib::Sound &indie::raylib::Sound::play() {
    ::PlaySound(*_sound);
    return *this;
}

indie::raylib::Sound &indie::raylib::Sound::stop() {
    ::StopSound(*_sound);
    return *this;
}

indie::raylib::Sound &indie::raylib::Sound::pause() {
    ::PauseSound(*_sound);
    return *this;
}

indie::raylib::Sound &indie::raylib::Sound::resume() {
    ::ResumeSound(*_sound);
    return *this;
}

indie::raylib::Sound &indie::raylib::Sound::setVolume(float volume) {
    ::SetSoundVolume(*_sound, volume);
    return *this;
}

indie::raylib::Sound &indie::raylib::Sound::setPitch(float pitch) {
    ::SetSoundPitch(*_sound, pitch);
    return *this;
}

bool indie::raylib::Sound::isPlaying() const {
    return ::IsSoundPlaying(*_sound);
}
