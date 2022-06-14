/**
 * @file Music.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Music encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Music.hpp"

indie::raylib::Music::Music(const std::string &fileName)
{
    _music = loadStream(fileName.c_str());
}

::Music indie::raylib::Music::loadStream(const std::string &fileName)
{
    return ::LoadMusicStream(fileName.c_str());
}

::Music indie::raylib::Music::loadStreamFromMemory(const std::string &fileType, unsigned char *data, int dataSize)
{
    return ::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
}

void indie::raylib::Music::unloadStream(::Music music)
{
    ::UnloadMusicStream(music);
}

void indie::raylib::Music::unloadStream()
{
    ::UnloadMusicStream(_music);
}

void indie::raylib::Music::playStream(::Music music)
{
    ::PlayMusicStream(music);
}

void indie::raylib::Music::playStream()
{
    ::PlayMusicStream(_music);
}

bool indie::raylib::Music::isStreamPlaying(::Music music)
{
    return ::IsMusicStreamPlaying(music);
}

bool indie::raylib::Music::isStreamPlaying()
{
    return ::IsMusicStreamPlaying(_music);
}

void indie::raylib::Music::updateStream(::Music music)
{
    ::UpdateMusicStream(music);
}

void indie::raylib::Music::updateStream()
{
    ::UpdateMusicStream(_music);
}

void indie::raylib::Music::stopStream(::Music music)
{
    ::StopMusicStream(music);
}

void indie::raylib::Music::stopStream()
{
    ::StopMusicStream(_music);
}

void indie::raylib::Music::pauseStream(::Music music)
{
    ::PauseMusicStream(music);
}

void indie::raylib::Music::pauseStream()
{
    ::PauseMusicStream(_music);
}

void indie::raylib::Music::resumeStream(::Music music)
{
    ::ResumeMusicStream(music);
}

void indie::raylib::Music::resumeStream()
{
    ::ResumeMusicStream(_music);
}

void indie::raylib::Music::seekStream(::Music music, float position)
{
    ::SeekMusicStream(music, position);
}

void indie::raylib::Music::seekStream(float position)
{
    ::SeekMusicStream(_music, position);
}

void indie::raylib::Music::setVolume(::Music music, float volume)
{
    ::SetMusicVolume(music, volume);
}

void indie::raylib::Music::setVolume(float volume)
{
    ::SetMusicVolume(_music, volume);
}

void indie::raylib::Music::setPitch(::Music music, float pitch)
{
    ::SetMusicPitch(music, pitch);
}

void indie::raylib::Music::setPitch(float pitch)
{
    ::SetMusicPitch(_music, pitch);
}

float indie::raylib::Music::getTimeLength(::Music music)
{
    return ::GetMusicTimeLength(music);
}

float indie::raylib::Music::getTimeLength()
{
    return ::GetMusicTimeLength(_music);
}

float indie::raylib::Music::getTimePlayed(::Music music)
{
    return ::GetMusicTimePlayed(music);
}

float indie::raylib::Music::getTimePlayed()
{
    return ::GetMusicTimePlayed(_music);
}
