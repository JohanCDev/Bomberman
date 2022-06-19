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
#include "../../../tools/Tools.hpp"
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
                UIPlayerDisplay::UIPlayerDisplay(indie::player::Player *player, vec2f pos, vec2f size)
                {
                    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem =
                        std::make_unique<indie::ecs::system::Draw2DSystem>();

                    this->_player = player;
                    this->_systems.push_back(std::move(draw2DSystem));
                    this->_position = pos;
                    this->_size = size;
                }

                void UIPlayerDisplay::createSingleTextEntity(std::string &str, vec2f position)
                {
                    std::unique_ptr<indie::ecs::entity::Entity> entity =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::TEXT);

                    entity->addComponent<ecs::component::Drawable2D>(
                        str, tools::Tools::getPercentage(2.f, false), BLACK);
                    entity->addComponent<indie::ecs::component::Transform>(
                        position.x, position.y, static_cast<float>(0.0), static_cast<float>(0.0));
                    this->_mainEntity.push_back(std::move(entity));
                }

                void UIPlayerDisplay::createImage()
                {
                    std::unique_ptr<indie::ecs::entity::Entity> sprite =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);

                    sprite->addComponent<ecs::component::Drawable2D>(this->getPlayerSpriteFilepath(),
                        tools::Tools::getPercentage(8.f, false), tools::Tools::getPercentage(8.f, false), WHITE);
                    sprite->addComponent<indie::ecs::component::Transform>(
                        this->_position.x - tools::Tools::getPercentage(4.f, false),
                        this->_position.y - tools::Tools::getPercentage(4.f, false), static_cast<float>(0.0),
                        static_cast<float>(0.0));
                    this->_mainEntity.push_back(std::move(sprite));
                }

                float UIPlayerDisplay::getNextYPos() const
                {
                    return (this->_mainEntity.back()
                                ->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM)
                                ->getY()
                        + tools::Tools::getPercentage(3.f, false));
                }

                indie::player::Player UIPlayerDisplay::getPlayer() const
                {
                    return *this->_player;
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
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
                    std::string playerStr("Player " + std::to_string(this->_player->getControllerId() + 1));
                    std::string speedStr("Speed: " + std::to_string(this->_player->getSpeed()));
                    std::string bombsStr("Bomb stock: " + std::to_string(this->_player->getBombStock()) + " / "
                        + std::to_string(this->_player->getMaxBombStock()));
                    std::string bombsRadiusStr("Bomb Range: " + std::to_string(this->_player->getBombRadius()));

                    container->addComponent<ecs::component::Drawable2D>(
                        "", this->_size.x, this->_size.y, this->_player->getColor());
                    container->addComponent<ecs::component::Transform>(this->_position.x, this->_position.y, 0.f, 0.f);
                    this->_mainEntity.push_back(std::move(container));
                    createImage();
                    createSingleTextEntity(playerStr,
                        {this->_position.x + tools::Tools::getPercentage(0.5f, false),
                            this->_position.y + tools::Tools::getPercentage(0.5f, false)});
                    createSingleTextEntity(
                        speedStr, {this->_position.x + tools::Tools::getPercentage(1.f, false), this->getNextYPos()});
                    createSingleTextEntity(
                        bombsStr, {this->_position.x + tools::Tools::getPercentage(1.f, false), this->getNextYPos()});
                    createSingleTextEntity(bombsRadiusStr,
                        {this->_position.x + tools::Tools::getPercentage(1.f, false), this->getNextYPos()});
                }

                void UIPlayerDisplay::update()
                {
                    ecs::component::Drawable2D *speedText =
                        this->_mainEntity.at(3)->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
                    ecs::component::Drawable2D *stockText =
                        this->_mainEntity.at(4)->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
                    ecs::component::Drawable2D *radiusText =
                        this->_mainEntity.at(5)->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
                    std::string speedStr("Speed: " + std::to_string(this->_player->getSpeed()));
                    std::string bombsStr("Bomb stock: " + std::to_string(this->_player->getBombStock()) + " / "
                        + std::to_string(this->_player->getMaxBombStock()));
                    std::string bombsRadiusStr("Bomb Range: " + std::to_string(this->_player->getBombRadius()));

                    speedText->setText(speedStr);
                    stockText->setText(bombsStr);
                    radiusText->setText(bombsRadiusStr);
                }

                void UIPlayerDisplay::draw()
                {
                    this->_systems[0]->update(this->_mainEntity);
                }
            } // namespace uiPlayerDisplay
        }     // namespace game
    }         // namespace screens
} // namespace indie