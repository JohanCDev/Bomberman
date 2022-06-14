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
        /// Sound class encapsulation
        class Sound {
            public:
                Sound() = default;
                Sound(const std::string& fileName);
                ~Sound() = default;

                /**
                * @brief Init audio device
                */
                ::Sound getSound() const;

                /**
                * @brief Init audio device
                */
                void initAudioDevice(void);

                /**
                * @brief Load sound from file
                */
                ::Sound load(const char *fileName);

                /**
                * @brief Update sound buffer with new data
                */
                void update(::Sound sound, const void *data, int samplesCount);

                /**
                * @brief Unload sound
                */
                static void unload(::Sound sound);
                void unload();

                /**
                * @brief Play a sound
                */
                static void play(::Sound sound);
                void play();

            /**
             * @brief Stop playing a sound
             */
            static void stop(::Sound sound);
            void stop();

            /**
             * @brief Pause a sound
             */
            static void pause(::Sound sound);
            void pause();

            /**
             * @brief Resume a paused sound
             */
            static void resume(::Sound sound);
            void resume();

            /**
             * @brief Set volume for a sound (1.0 is max level)
             */
            static void setVolume(::Sound sound, float volume);
            void setVolume(float volume);

            /**
             * @brief Set pitch for a sound (1.0 is base level)
             */
            static void setPitch(::Sound sound, float pitch);
            void setPitch(float pitch);

            /**
             * @brief Check if a sound is currently playing
             */
            static bool isPlaying(::Sound sound);
            bool isPlaying() const;

          private:
            ::Sound _sound;
        };
    } // namespace raylib
} // namespace indie

#endif /* !SOUND_HPP_ */
