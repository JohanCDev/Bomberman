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
             * @param fileName Filepath to the sound file
             */
            Sound(const std::string &fileName);
            /**
             * @brief Destroy the Sound object
             * 
             */
            ~Sound() = default;
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
             * @brief Set volume for a sound (1.0 is max level)
             * 
             * 
             * @param sound The sound stream
             * @param volume The volume for the sound
             */
            static void setVolume(::Sound sound, float volume);
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
        };
    } // namespace raylib
} // namespace indie

#endif /* !SOUND_HPP_ */
