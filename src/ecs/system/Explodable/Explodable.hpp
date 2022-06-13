/**
 * @file Explodable.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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
            /// @brief Explodable system
            class Explodable : public ISystem {
              public:
                Explodable();
                ~Explodable();

                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);
                void destroyBoxes(std::vector<int> &compoToRemove,
                    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
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
