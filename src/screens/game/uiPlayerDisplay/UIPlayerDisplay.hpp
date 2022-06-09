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
                class UIPlayerDisplay {
                  public:
                    UIPlayerDisplay(indie::player::Player &player, vec2f pos, vec2f size);
                    ~UIPlayerDisplay() = default;
                    void createSingleTextEntity(std::string &str, vec2f position);
                    void createImage();
                    const std::string getPlayerSpriteFilepath() const;
                    float getNextYPos() const;
                    indie::player::Player getPlayer() const;
                    void create();
                    void draw();

                  private:
                    std::unique_ptr<indie::player::Player> _player;
                    vec2f _position;
                    vec2f _size;
                    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _mainEntity;
                    std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
                };
            } // namespace uiPlayerDisplay
        }     // namespace game
    }         // namespace screens
} // namespace indie

#endif