/**
 * @file Sound.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Sound encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Sound class encapsulation
        class Sound {
            public:
                /**
                 * @brief Construct a new Sound object
                 * 
                 */
                Sound() = default;
                /**
                 * @brief Construct a new Sound object
                 * 
                 * @param fileName File path to the sound file
                 */
                Sound(const std::string& fileName);
                /**
                 * @brief Destroy the Sound object
                 * 
                 */
                ~Sound() = default;
                /**
                * @brief Get Sound
                * 
                * @return Sound Sound Object
                */
                ::Sound getSound() const;
                /**
                * @brief Init audio device
                */
                static void initAudioDevice(void);
                /**
                * @brief Load sound from file
                * 
                * @param fileName File path to the sound file
                * 
                * @return Sound Sound object
                */
                ::Sound load(const char *fileName);
                /**
                * @brief Update sound buffer with new data
                * 
                * @param sound Sound buffer
                * @param data Data for update
                * @param samplesCount Samples count
                */
                void update(::Sound sound, const void *data, int samplesCount);
                /**
                * @brief Unload sound
                * 
                * @param sound Sound object
                */
                static void unload(::Sound sound);
                /**
                 * @brief Unload sound
                 * 
                 */
                void unload();
                /**
                 * @brief Play a sound
                 * 
                 * @param sound The sound stream
                 */
                static void play(::Sound sound);
                /**
                 * @brief Play a sound
                 * 
                 */
                void play();
                /**
                 * @brief Stop playing a sound
                 * 
                 * @param sound The sound stream
                 */
                static void stop(::Sound sound);
                /**
                 * @brief Stop playing a sound
                 * 
                 */
                void stop();
                /**
                 * @brief Pause a sound
                 * 
                 * @param sound The sound stream
                 */
                static void pause(::Sound sound);
                /**
                 * @brief Pause a sound
                 * 
                 */
                void pause();
                /**
                 * @brief Resume a paused sound
                 * 
                 * @param sound The sound stream
                 */
                static void resume(::Sound sound);
                /**
                 * @brief Resume a paused sound
                 * 
                 */
                void resume();
                /**
                * @brief Get the volume
                * 
                * @return float Volume value
                */
                float getVolume() const;
                /**
                * @brief Set volume for a sound (1.0 is max level)
                * 
                * @param volume The volume for the sound
                */
                void setVolume(float volume);
                /**
                * @brief Set pitch for a sound (1.0 is base level)
                * 
                * @param sound The sound stream
                * @param pitch The pitch for the sound
                */
                static void setPitch(::Sound sound, float pitch);
                /**
                 * @brief Set the pitch for a sound (1.0 is base level)
                 * 
                 * @param pitch The pitch for the sound
                 */
                void setPitch(float pitch);
                /**
                 * @brief Check if a sound is currently playing
                 * 
                 * @param sound The sound stream
                 * @return true The sound is currently playing
                 * @return false The sound isn't currently playing
                 */
                static bool isPlaying(::Sound sound);
                /**
                 * @brief Check if a sound is currently playing
                 * 
                 * @return true The sound is currently playing
                 * @return false The sound isn't currently playing
                 */
                bool isPlaying() const;

          private:
            /**
             * @brief The sound stream
             * 
             */
            ::Sound _sound;
            /**
             * @brief Volume value
             * 
             */
            float _volume;
        };
    } // namespace raylib
} // namespace indie

#endif /* !SOUND_HPP_ */