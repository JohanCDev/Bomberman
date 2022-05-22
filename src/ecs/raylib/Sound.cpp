/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#include "Sound.hpp"

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
