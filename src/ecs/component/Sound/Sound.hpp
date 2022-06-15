/**
 * @file Sound.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Sound component header file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Sound component
            class Sound : public IComponent {
              public:
                Sound(std::string soundPath, bool play, float volume = 1.0f);
                ~Sound();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                std::string getSoundPath() const;
                indie::raylib::Sound getSound() const;
                bool getPlay() const;
                float getVolume() const;

                void setSoundPath(std::string soundPath);
                void setSound(std::string soundPath);
                void setPlay(bool play);
                void setVolume(float volume);

              private:
                std::string _soundPath;
                bool _play;
                float _volume;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
