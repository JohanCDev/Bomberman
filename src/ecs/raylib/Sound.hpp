/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>
#include "Raylib.hpp"

namespace Raylib {
    class Sound {
        public:
            Sound(const std::string& fileName);
            ~Sound();

            Sound &play();
            Sound &stop();
            Sound &pause();
            Sound &resume();

            // TODO: Set volume, set pitch, isPlaying
        private:
			std::shared_ptr<::Sound> _sound;
    };
}

#endif /* !SOUND_HPP_ */
