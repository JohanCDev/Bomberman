/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <memory>
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

            Sound& setVolume(float volume);
            Sound& setPitch(float pitch);

            bool isPlaying() const;
        private:
			std::shared_ptr<::Sound> _sound;
    };
}

#endif /* !SOUND_HPP_ */
