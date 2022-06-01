/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "../component/IComponent.hpp"
#include "../entity/Entity.hpp"

namespace indie
{
    namespace ecs
    {

        enum SystemType { DRAWABLE3DSYSTEM, DRAWABLE2DSYSTEM, MOVEMENTSYSTEM };

        class ISystem {
          public:
            virtual ~ISystem() = default;

            virtual void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) = 0;
            virtual indie::ecs::SystemType getSystemType() const = 0;

          private:
        };

        class MovementSystem : public ISystem {
          public:
            MovementSystem()
            {
            }
            ~MovementSystem()
            {
            }

            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;
            indie::ecs::SystemType getSystemType() const override;

          private:
        };

        class Draw2DSystem : public ISystem {
          public:
            Draw2DSystem();
            ~Draw2DSystem();

            void drawText(auto drawableCompo, auto transformCompo);
            void drawRectangle(auto drawableCompo, auto transformCompo);
            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;
            indie::ecs::SystemType getSystemType() const override;

          private:
        };

        class Draw3DSystem : public ISystem {
          public:
            Draw3DSystem();
            ~Draw3DSystem();

            void drawSphere(auto drawableCompo, auto transformCompo);
            void drawCube(auto drawableCompo, auto transformCompo);
            void update(std::vector<std::unique_ptr<indie::ecs::Entity>> &entities) override;
            indie::ecs::SystemType getSystemType() const override;

          private:
        };
    } // namespace ecs
} // namespace indie

#endif /* !SYSTEM_HPP_ */
