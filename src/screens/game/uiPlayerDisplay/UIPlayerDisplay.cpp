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

                void UIPlayerDisplay::create_single_text_entity(std::string &str, vec2f position)
                {
                    std::unique_ptr<indie::ecs::entity::Entity> entity = std::make_unique<indie::ecs::entity::Entity>();

                    entity->addComponent<ecs::component::Drawable2D>(str, 20.f, BLACK);
                    entity->addComponent<indie::ecs::component::Transform>(
                        position.x, position.y, static_cast<float>(0.0), static_cast<float>(0.0));
                    this->_mainEntity.push_back(std::move(entity));
                }

                float UIPlayerDisplay::getNextYPos() const
                {
                    return (this->_mainEntity.back()
                                ->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM)
                                ->getY()
                        + 22.f);
                }

                indie::player::Player UIPlayerDisplay::getPlayer() const
                {
                    return *this->_player.get();
                }

                void UIPlayerDisplay::create()
                {
                    std::unique_ptr<indie::ecs::entity::Entity> container =
                        std::make_unique<indie::ecs::entity::Entity>();
                    std::string playerStr("Player " + std::to_string(this->_player->getControllerId() + 1));
                    std::string speedStr("Speed: " + std::to_string(this->_player->getSpeed()));
                    std::string bombsStr("Bomb stock: " + std::to_string(this->_player->getBombStock()) + " / "
                        + std::to_string(this->_player->getMaxBombStock()));
                    std::string crossWallInfo(this->_player->getCrossWalls() ? "Activated" : "Not actvated");
                    std::string crossWallsStr("Cross walls: " + crossWallInfo);
                    std::string bombsRadiusStr("Bomb Radius: " + std::to_string(this->_player->getBombRadius()));

                    container->addComponent<ecs::component::Drawable2D>(
                        "", this->_size.x, this->_size.y, this->_player->getColor());
                    container->addComponent<ecs::component::Transform>(this->_position.x, this->_position.y, 0.f, 0.f);
                    this->_mainEntity.push_back(std::move(container));
                    create_single_text_entity(playerStr, {this->_position.x + 2, this->_position.y + 2});
                    create_single_text_entity(speedStr, {this->_position.x + 2, this->getNextYPos()});
                    create_single_text_entity(bombsStr, {this->_position.x + 2, this->getNextYPos()});
                    create_single_text_entity(crossWallsStr, {this->_position.x + 2, this->getNextYPos()});
                    create_single_text_entity(bombsRadiusStr, {this->_position.x + 2, this->getNextYPos()});
                }

                void UIPlayerDisplay::draw()
                {
                    this->_systems[0]->update(this->_mainEntity);
                }
            } // namespace uiPlayerDisplay
        }     // namespace game
    }         // namespace screens
} // namespace indie