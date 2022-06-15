/**
 * @file Draw3D.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Draw3D system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DRAW3D_HPP_
#define DRAW3D_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Draw3D system
            class Draw3DSystem : public ISystem {
              public:
                /**
                 * @brief Create a new draw 3d system.
                 */
                Draw3DSystem() {}
                /**
                 * @brief Destroy a draw 3d system.
                 */
                ~Draw3DSystem() {}
                /**
                 * @brief Draw sphere with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the radius and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawSphere(auto drawableCompo, auto transformCompo);

                /**
                 * @brief Draw cube with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawCube(auto drawableCompo, auto transformCompo);

                /**
                 * @brief Draw all given entities with Drawable3D component.
                 *
                 * @param entities the entities to draw.
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return indie::ecs::system::SystemType SystemType
                 */
                indie::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !DRAW3D_HPP_ */
