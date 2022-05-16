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

namespace ecs {
    class IComponent {
        public:
            virtual void update(float param1, float param2) = 0;
            virtual float getX() = 0;
            virtual float getY() = 0;
            // virtual void draw() = 0;
        protected:

        private:
    };

    class Position : public IComponent
    {
        public:
            Position(float param1, float param2) {
                this->_x = param1;
                this->_y = param2;
            }

            void update(float param1, float param2) override {
                this->_x = param1;
                this->_y = param2;
            }

            float getX() override {
                return (this->_x);
            }

            float getY() override {
                return (this->_y);
            }

        protected:
        private:
            float _x;
            float _y;
            
    };

    class Movement : public IComponent
    {
        public:
            Movement(float param1, float param2) {
                this->_x = param1;
                this->_y = param2;
            }

            void update(float param1, float param2) override {
                this->_x = param1;
                this->_y = param2;
            }

            float getX() override {
                return (this->_x);
            }

            float getY() override {
                return (this->_y);
            }

        protected:
        private:
            float _x;
            float _y;   
    };

}

#endif /* !COMPONENT_HPP_ */
