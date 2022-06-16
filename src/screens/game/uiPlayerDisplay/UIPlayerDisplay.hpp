/**
 * @file UIPlayerDisplay.cpp
 * @author johan.chrillesen@epitech.eu
 * @brief The user interface player characteristics display
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef UIPLAYERDISPLAY_HPP
#define UIPLAYERDISPLAY_HPP

#include "../../../ecs/component/Drawable2D/Drawable2D.hpp"
#include "../../../ecs/entity/Entity.hpp"
#include "../../../ecs/system/Draw2D/Draw2D.hpp"
#include "../../../player/Player.hpp"
#include "Vec2.hpp"

#include <memory>
#include <string>

namespace indie
{
    namespace screens
    {
        namespace game
        {
            namespace uiPlayerDisplay
            {
                /**
                * @brief Class for the Player's UI
                * 
                */
                class UIPlayerDisplay {
                  public:
                    /**
                     * @brief Construct a new UIPlayerDisplay object
                     * 
                     * @param player Player targeted by UI Information Display
                     * @param pos The position of the UI for player
                     * @param size The size of the UI for player
                     */
                    UIPlayerDisplay(indie::player::Player *player, vec2f pos, vec2f size);
                    /**
                     * @brief Destroy the UIPlayerDisplay object
                     * 
                     */
                    ~UIPlayerDisplay() = default;
                    /**
                     * @brief Create the text entity for the player's UI
                     * 
                     * @param str The text to display
                     * @param position The position to display the text
                     */
                    void createSingleTextEntity(std::string &str, vec2f position);
                    /**
                     * @brief Create an image for the player's UI
                     * 
                     */
                    void createImage();
                    /**
                     * @brief Get the Player Sprite Filepath
                     * 
                     * @return const std::string the filepath to the player Sprite
                     */
                    const std::string getPlayerSpriteFilepath() const;
                    /**
                     * @brief Get the Next Y Pos of the Player's UI
                     * 
                     * @return float The position of the next position
                     */
                    float getNextYPos() const;
                    /**
                     * @brief Get the Player object
                     * 
                     * @return indie::player::Player The object of the targeted player
                     */
                    indie::player::Player getPlayer() const;
                    /**
                     * @brief Create a new UI for player
                     * 
                     */
                    void create();
                    /**
                     * @brief Update the player's UI
                     * 
                     */
                    void update();
                    /**
                     * @brief Draw the player's UI
                     * 
                     */
                    void draw();

                  private:
                    /**
                     * @brief The player
                     * 
                     */
                    indie::player::Player *_player;
                    /**
                     * @brief Position for the UI
                     * 
                     */
                    vec2f _position;
                    /**
                     * @brief Size for the UI
                     * 
                     */
                    vec2f _size;
                    /**
                     * @brief Vector for entities of the UI
                     * 
                     */
                    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _mainEntity;
                    /**
                     * @brief Vector for systems of the UI
                     * 
                     */
                    std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
                };
            } // namespace uiPlayerDisplay
        }     // namespace game
    }         // namespace screens
} // namespace indie

#endif