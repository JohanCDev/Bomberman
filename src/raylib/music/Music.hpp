/**
 * @file Music.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Music encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Music class encapsulation
        class Music {
          public:
            Music(const std::string &fileName);
            ~Music() = default;

            /**
             * @brief Load music stream from file
             */
            static ::Music loadStream(const std::string &fileName);

            /**
             * @brief Load music stream from data
             */
            static ::Music loadStreamFromMemory(const std::string &fileType, unsigned char *data, int dataSize);
            /**

            * @brief Unload music stream
            */
            static void unloadStream(::Music music);
            void unloadStream(void);

            /**
             * @brief Start music playing
             */
            static void playStream(::Music music);
            void playStream(void);

            /**
             * @brief Check if music is playing
             */
            static bool isStreamPlaying(::Music music);
            bool isStreamPlaying(void);

            /**
             * @brief Updates buffers for music streaming
             */
            static void updateStream(::Music music);
            void updateStream(void);

            /**
             * @brief Stop music playing
             */
            static void stopStream(::Music music);
            void stopStream(void);

            /**
             * @brief Pause music playing
             */
            static void pauseStream(::Music music);
            void pauseStream(void);

            /**
             * @brief Resume playing paused music
             */
            static void resumeStream(::Music music);
            void resumeStream(void);

            /**
             * @brief Seek music to a position (in seconds)
             */
            static void seekStream(::Music music, float position);
            void seekStream(float position);

            /**
             * @brief Set volume for music (1.0 is max level)
             */
            static void setVolume(::Music music, float volume);
            void setVolume(float volume);

            /**
             * @brief Set pitch for a music (1.0 is base level)
             */
            static void setPitch(::Music music, float pitch);
            void setPitch(float pitch);

            /**
             * @brief Get music time length (in seconds)
             */
            static float getTimeLength(::Music music);
            float getTimeLength(void);

            /**
             * @brief Get current music time played (in seconds)
             */
            static float getTimePlayed(::Music music);
            float getTimePlayed(void);

          private:
            ::Music _music;
        };
    } // namespace raylib
} // namespace indie

#endif /* !MUSIC_HPP_ */
