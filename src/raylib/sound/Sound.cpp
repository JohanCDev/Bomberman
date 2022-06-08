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

void indie::raylib::Sound::play(::Sound sound) {
    ::PlaySound(sound);
}

void indie::raylib::Sound::play() {
    ::PlaySound(_sound);
}

void indie::raylib::Sound::stop(::Sound sound) {
    ::StopSound(sound);
}

void indie::raylib::Sound::stop() {
    ::StopSound(_sound);
}

void indie::raylib::Sound::pause(::Sound sound) {
    ::PauseSound(sound);
}

void indie::raylib::Sound::pause() {
    ::PauseSound(_sound);
}

void indie::raylib::Sound::resume(::Sound sound) {
    ::ResumeSound(sound);
}

void indie::raylib::Sound::resume() {
    ::ResumeSound(_sound);
}

void indie::raylib::Sound::setVolume(::Sound sound, float volume) {
    ::SetSoundVolume(sound, volume);
}

void indie::raylib::Sound::setVolume(float volume) {
    ::SetSoundVolume(_sound, volume);
}

void indie::raylib::Sound::setPitch(float pitch) {
    ::SetSoundPitch(_sound, pitch);
}

void indie::raylib::Sound::setPitch(::Sound sound, float pitch) {
    ::SetSoundPitch(sound, pitch);
}

bool indie::raylib::Sound::isPlaying(::Sound sound) {
    return ::IsSoundPlaying(sound);
}

bool indie::raylib::Sound::isPlaying() const {
    return ::IsSoundPlaying(_sound);
}
