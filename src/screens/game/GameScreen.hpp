/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#ifndef GAMESCREEN_HPP_
#define GAMESCREEN_HPP_

#include <memory>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/system/ISystem.hpp"
#include "../IScreen.hpp"
#include "events.hpp"
#include "uiPlayerDisplay/UIPlayerDisplay.hpp"

namespace indie
{
    namespace menu
    {
        class GameScreen : public IScreen {
          public:
            GameScreen();
            ~GameScreen() = default;
            void draw() override;
            void update(float delta) override;
            void handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            indie::raylib::Camera3D getCamera() const;
            void initMap(std::vector<std::vector<char>> map);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>> _infoPlayers;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            indie::raylib::Camera3D _camera;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
