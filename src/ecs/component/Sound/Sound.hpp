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
                /**
                 * @brief Construct a new Sound object
                 * 
                 * @param soundPath Filepath to the sound file
                 * @param play Play the sound or not
                 */
                Sound(std::string soundPath, bool play);
                /**
                 * @brief Destroy the Sound object
                 * 
                 */
                ~Sound();
                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Sound Path of the component
                 * 
                 * @return std::string The soundpath of the component
                 */
                std::string getSoundPath() const;
                /**
                 * @brief Get the Sound Stream
                 * 
                 * @return indie::raylib::Sound The sound stream of the component
                 */
                indie::raylib::Sound getSound() const;
                /**
                 * @brief Get if the sound playing 
                 * 
                 * @return true The sound is actually playing
                 * @return false The sound isn't actually playing
                 */
                bool getPlay() const;
                /**
                 * @brief Set the Sound Path of the component
                 * 
                 * @param soundPath File path to the sound file
                 */
                void setSoundPath(std::string soundPath);
                /**
                 * @brief Set the Sound stream of the component
                 * 
                 * @param soundPath Filepath to the sound file
                 */
                void setSound(std::string soundPath);
                /**
                 * @brief Set the sound on play
                 * 
                 * @param play Play the sound or not
                 */
                void setPlay(bool play);

              private:
                /**
                 * @brief Soundfile's filepath
                 * 
                 */
                std::string _soundPath;
                /**
                 * @brief State of the sound
                 * 
                 */
                bool _play;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
