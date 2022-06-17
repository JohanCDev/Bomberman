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
        /// @brief Music class encapsulation
        class Music {
          public:
            /**
             * @brief Construct a new Music object
             * 
             * @param fileName Filepath to the music file
             */
            Music(const std::string &fileName);
            /**
             * @brief Destroy the Music object
             * 
             */
            ~Music() = default;
            /**
             * @brief Load music stream from file
             * 
             * @param fileName Filepath to the music file
             * 
             * @return Music The music stream
             */
            static ::Music loadStream(const std::string &fileName);
            /**
             * @brief Load music stream from data
             * 
             * @param fileType The type of file
             * @param data The data to load
             * @param dataSize The data size to load
             * 
             * @return Music The music stream
             */
            static ::Music loadStreamFromMemory(const std::string &fileType, unsigned char *data, int dataSize);
            /**
             * @brief Unload Music stream
             * 
             * @param music The music stream to unload
             */
            static void unloadStream(::Music music);
            /**
             * @brief Unload Music stream
             * 
             */
            void unloadStream(void);
            /**
             * @brief Start music playing
             * 
             * @param music Music stream to paly
             */
            static void playStream(::Music music);
            /**
             * @brief Start music playing
             * 
             */
            void playStream(void);
            /**
             * @brief Check if music is playing
             * 
             * @param music The music stream played
             * 
             * @return true The music is actually playing
             * @return false The music isn't actually playing
             */
            static bool isStreamPlaying(::Music music);
            /**
             * @brief Check if music is playing
             * 
             * @return true The music is actually playing
             * @return false The music isn't actually playing
             */
            bool isStreamPlaying(void);
            /**
             * @brief Update buffers for music streaming
             * 
             * @param music The music stream to update
             */
            static void updateStream(::Music music);
            /**
             * @brief Update buffers for music streaming
             * 
             */
            void updateStream(void);
            /**
             * @brief Stop music playing
             * 
             * @param music The music stream to stop
             */
            static void stopStream(::Music music);
            /**
             * @brief Stop music playing
             * 
             */
            void stopStream(void);
            /**
             * @brief Pause music playing
             * 
             * @param music The music stream to pause
             */
            static void pauseStream(::Music music);
            /**
             * @brief Pause music playing
             * 
             */
            void pauseStream(void);
            /**
             * @brief Resume playing paused music
             * 
             * @param music The music stream to resume playing
             */
            static void resumeStream(::Music music);
            /**
             * @brief Resume playing paused music
             * 
             */
            void resumeStream(void);
            /**
             * @brief Seek music to a position (in seconds)
             * 
             * @param music The music stream to seek
             * @param position The position to seek the music
             */
            static void seekStream(::Music music, float position);
            /**
             * @brief Seek music to a position
             * 
             * @param position The position to seek the music
             */
            void seekStream(float position);
            /**
             * @brief Set volume for music (1.0 is max level)
             * 
             * @param music The music stream
             * @param volume The music volume
             */
            static void setVolume(::Music music, float volume);
            /**
             * @brief Set volume for music (1.0 is max level)
             * 
             * @param volume The music volume
             */
            void setVolume(float volume);
            /**
             * @brief Set pitch for a music (1.0 is base level)
             * 
             * @param music The music stream
             * @param pitch The music pitch
             */
            static void setPitch(::Music music, float pitch);
            /**
             * @brief Set pitch for a music (1.0 is max level)
             * 
             * @param pitch The music pitch
             */
            void setPitch(float pitch);
            /**
             * @brief Get music time length (in seconds)
             * 
             * @param music The music stream
             * 
             * @return float The music time length
             */
            static float getTimeLength(::Music music);
            /**
             * @brief Get the Time Length object
             * 
             * @return float The music time length
             */
            float getTimeLength(void);
            /**
             * @brief Get current music time played (in seconds)
             * 
             * @param music The music stream
             * 
             * @return float The music time played
             */
            static float getTimePlayed(::Music music);
            /**
             * @brief Get the Time Played object
             * 
             * @return float The music time played
             */
            float getTimePlayed(void);

          private:
            /**
             * @brief The music stream
             * 
             */
            ::Music _music;
        };
    } // namespace raylib
} // namespace indie

#endif /* !MUSIC_HPP_ */
