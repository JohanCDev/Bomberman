/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Sound {
            public:
                Sound(const std::string& fileName);
                ~Sound();

                /**
                * @brief Play a sound
                */
                void play();

                /**
                * @brief Stop playing a sound
                */
                void stop();

                /**
                * @brief Pause a sound
                */
                void pause();


                /**
                * @brief Resume a paused sound
                */
                void resume();

                /**
                * @brief Set volume for a sound (1.0 is max level)
                */
                void setVolume(float volume);

                /**
                * @brief Set pitch for a sound (1.0 is base level)
                */
                void setPitch(float pitch);

                /**
                * @brief Check if a sound is currently playing
                */
                bool isPlaying() const;
            private:
                ::Sound _sound;
        };
    }
}

#endif /* !SOUND_HPP_ */
