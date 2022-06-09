/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#ifndef EXPLODABLE_HPP_
#define EXPLODABLE_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            class Explodable : public ISystem {
              public:
                Explodable();
                ~Explodable();

                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);
                void destroyBoxes(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
                    indie::ecs::component::Explodable *explodableCompo,
                    indie::ecs::component::Transform *transformCompo);

                indie::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !EXPLODABLE_HPP_ */
