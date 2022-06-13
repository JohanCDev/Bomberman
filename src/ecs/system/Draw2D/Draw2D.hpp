/*
** EPITECH PROJECT, 2022
** Draw2D
** File description:
** Draw2D
*/

#ifndef DRAW2D_HPP_
#define DRAW2D_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Draw2D system
            class Draw2DSystem : public ISystem {
              public:
                /**
                 * @brief Create new draw 2d system.
                 */
                Draw2DSystem()
                {
                }

                /**
                 * @brief Destroy draw 2d system.
                 */
                ~Draw2DSystem()
                {
                }

                /**
                 * @brief Draw text with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the text and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawText(auto drawableCompo, auto transformCompo);

                /**
                 * @brief Draw rectangle with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawRectangle(auto drawableCompo, auto transformCompo);

                /**
                 * @brief Draw all given entities with Drawable2D component.
                 *
                 * @param entities all entities to draw.
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                indie::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !DRAW2D_HPP_ */
