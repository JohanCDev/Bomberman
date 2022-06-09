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

#include "UIPlayerDisplay.hpp"
#include "../../../ecs/component/IComponent.hpp"
#include "../../../player/Player.hpp"
#include "Colors.hpp"
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
                UIPlayerDisplay::UIPlayerDisplay(indie::player::Player &player, vec2f pos, vec2f size)
                {
                    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem =
                        std::make_unique<indie::ecs::system::Draw2DSystem>();

                    this->_player = std::make_unique<indie::player::Player>(player);
                    this->_systems.push_back(std::move(draw2DSystem));
                    this->_position = pos;
                    this->_size = size;
                }

                void UIPlayerDisplay::createSingleTextEntity(std::string &str, vec2f position)
                {
                    std::unique_ptr<indie::ecs::entity::Entity> entity = std::make_unique<indie::ecs::entity::Entity>();

                    entity->addComponent<ecs::component::Drawable2D>(str, 20.f, BLACK);
                    entity->addComponent<indie::ecs::component::Transform>(
                        position.x, position.y, static_cast<float>(0.0), static_cast<float>(0.0));
                    this->_mainEntity.push_back(std::move(entity));
                }

                void UIPlayerDisplay::createImage()
                {
                    std::unique_ptr<indie::ecs::entity::Entity> sprite = std::make_unique<indie::ecs::entity::Entity>();

                    sprite->addComponent<ecs::component::Drawable2D>(this->getPlayerSpriteFilepath(),
                        static_cast<float>(700.0), static_cast<float>(700.0), this->_player->getColor());
                    sprite->addComponent<indie::ecs::component::Transform>(
                        this->_position.x, this->_position.y, static_cast<float>(0.0), static_cast<float>(0.0));
                    this->_mainEntity.push_back(std::move(sprite));
                }

                float UIPlayerDisplay::getNextYPos() const
                {
                    return (this->_mainEntity.back()
                                ->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM)
                                ->getY()
                        + 25.f);
                }

                indie::player::Player UIPlayerDisplay::getPlayer() const
                {
                    return *this->_player.get();
                }

                static bool compareColor(Color a, Color b)
                {
                    return (a.a == b.a && a.b == b.b && a.g == b.g && a.r == b.r);
                }

                const std::string UIPlayerDisplay::getPlayerSpriteFilepath() const
                {
                    Color playerColor = this->_player->getColor();

                    if (compareColor(playerColor, BLUEPLAYERCOLOR))
                        return "./assets/blue.png";
                    else if (compareColor(playerColor, GREENPLAYERCOLOR))
                        return "./assets/green.png";
                    else if (compareColor(playerColor, REDPLAYERCOLOR))
                        return "./assets/red.png";
                    else
                        return "./assets/yellow.png";
                }

                void UIPlayerDisplay::create()
                {
                    std::unique_ptr<indie::ecs::entity::Entity> container =
                        std::make_unique<indie::ecs::entity::Entity>();
                    std::string playerStr("Player " + std::to_string(this->_player->getControllerId() + 1));
                    std::string speedStr("Speed: " + std::to_string(this->_player->getSpeed()));
                    std::string bombsStr("Bomb stock: " + std::to_string(this->_player->getBombStock()) + " / "
                        + std::to_string(this->_player->getMaxBombStock()));
                    std::string crossWallInfo(this->_player->getCrossWalls() ? "Yes" : "No");
                    std::string crossWallsStr("Cross walls: " + crossWallInfo);
                    std::string bombsRadiusStr("Bomb Radius: " + std::to_string(this->_player->getBombRadius()));
                    std::string filepath = this->getPlayerSpriteFilepath();
                    std::cout << filepath << std::endl;

                    container->addComponent<ecs::component::Drawable2D>(
                        "", this->_size.x, this->_size.y, this->_player->getColor());
                    container->addComponent<ecs::component::Transform>(this->_position.x, this->_position.y, 0.f, 0.f);
                    this->_mainEntity.push_back(std::move(container));
                    createImage();
                    createSingleTextEntity(playerStr, {this->_position.x + 5, this->_position.y + 5});
                    createSingleTextEntity(speedStr, {this->_position.x + 10, this->getNextYPos()});
                    createSingleTextEntity(bombsStr, {this->_position.x + 10, this->getNextYPos()});
                    createSingleTextEntity(crossWallsStr, {this->_position.x + 10, this->getNextYPos()});
                    createSingleTextEntity(bombsRadiusStr, {this->_position.x + 10, this->getNextYPos()});
                }

                void UIPlayerDisplay::draw()
                {
                    this->_systems[0]->update(this->_mainEntity);
                }
            } // namespace uiPlayerDisplay
        }     // namespace game
    }         // namespace screens
} // namespace indie