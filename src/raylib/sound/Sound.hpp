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

                void play();
                void stop();
                void pause();
                void resume();

                void setVolume(float volume);
                void setPitch(float pitch);

                bool isPlaying() const;
            private:
                ::Sound _sound;
        };
    }
}

#endif /* !SOUND_HPP_ */
