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
            float x;
            float y;

        protected:

        private:
    };

    class Position : public IComponent
    {
        public:
            Position(float param1, float param2) {
                this->x = param1;
                this->y = param2;
            }
        protected:
        private:
            
    };

    class Movement : public IComponent
    {
        public:
            Movement(float param1, float param2) {
                this->x = param1;
                this->y = param2;
            }
        protected:
        private:
            
    };
}

#endif /* !COMPONENT_HPP_ */
