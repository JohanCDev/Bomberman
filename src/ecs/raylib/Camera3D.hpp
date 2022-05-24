/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Camera3D
*/

#ifndef CAMERA3D_HPP_
#define CAMERA3D_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Camera3D {
        public:
            Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int type);
            ~Camera3D();

        private:
            ::Vector3 _position;
            ::Vector3 _target;
            ::Vector3 _up;
            float _fovy;
            int _type;
    };
}

#endif /* !CAMERA3D_HPP_ */
