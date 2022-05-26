/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

extern "C"
{
#include <raylib.h>
}

namespace indie
{
    namespace ecs
    {
        /**
         * @brief Generic component
         */
        class IComponent {
          public:
            /**
             * @brief Updates a component
             *
             * @param param1
             * @param param2
             */
            virtual void update(float param1, float param2) = 0;
            /**
             * @brief Get the x position
             *
             * @return float x position
             */
            virtual float getX() = 0;
            /**
             * @brief Get the y position
             *
             * @return float y position
             */
            virtual float getY() = 0;
            // virtual void draw() = 0;
          protected:
          private:
        };

        /**
         * @brief Position element
         * Contains a position and handle its modifications
         */
        class Position : public IComponent {
          public:
            /**
             * @brief Construct a new Position object
             *
             * @param param1 x position
             * @param param2 y positition
             */
            Position(float param1, float param2)
            {
                this->_x = param1;
                this->_y = param2;
            }

            /**
             * @brief Update a position
             *
             * @param param1 new x position
             * @param param2 new y position
             */
            void update(float param1, float param2) override
            {
                this->_x = param1;
                this->_y = param2;
            }

            /**
             * @brief Get the x position
             *
             * @return float x position
             */
            float getX() override
            {
                return (this->_x);
            }

            /**
             * @brief Get the y position
             *
             * @return float y position
             */
            float getY() override
            {
                return (this->_y);
            }

          protected:
          private:
            float _x;
            float _y;
        };

        /**
         * @brief Movement element
         *
         */
        class Movement : public IComponent {
          public:
            /**
             * @brief Construct a new Movement object
             *
             * @param param1 x movement
             * @param param2 y movement
             */
            Movement(float param1, float param2)
            {
                this->_x = param1;
                this->_y = param2;
            }

            /**
             * @brief Update the Movement object values
             *
             * @param param1 x movement
             * @param param2 y movement
             */
            void update(float param1, float param2) override
            {
                this->_x = param1;
                this->_y = param2;
            }

            /**
             * @brief Get the x movement
             *
             * @return float x movement
             */
            float getX() override
            {
                return (this->_x);
            }

            /**
             * @brief Get the y movement
             *
             * @return float y movement
             */
            float getY() override
            {
                return (this->_y);
            }

          protected:
          private:
            float _x;
            float _y;
        };
    } // namespace ecs
} // namespace indie

#endif /* !COMPONENT_HPP_ */
