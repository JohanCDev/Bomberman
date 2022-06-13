/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
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
                Sound(std::string soundPath, bool play);
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

                void setSoundPath(std::string soundPath);
                void setSound(std::string soundPath);
                void setPlay(bool play);

              private:
                std::string _soundPath;
                bool _play;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
