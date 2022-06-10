/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetFpsScreen.hpp
*/

#ifndef SETFPSSCREEN_HPP_
#define SETFPSSCREEN_HPP_

#include <map>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class SetFpsScreen : public IScreen {
            enum cursorPosition { FPS_30 = 0, FPS_60 = 1 };

          public:
            SetFpsScreen();
            ~SetFpsScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            void setPreviousScene(bool scene);
            int checkCursorPosition(bool direction);

          private:
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            std::map<cursorPosition, float> _positionsCursor;
            int _cursorPosition;
        };
    } // namespace menu
} // namespace indie

#endif /* !SetFpsScreen_HPP_ */
