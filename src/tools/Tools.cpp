/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Tools
*/

#include "Tools.hpp"
#include "../raylib/Raylib.hpp"

namespace indie::tools
{
    Tools::Tools()
    {
    }

    Tools::~Tools()
    {
    }

    float Tools::getPercentage(float percent, bool isWidth)
    {
        float windowDim = isWidth ? static_cast<float>(indie::raylib::Window::getWidth())
                                  : static_cast<float>(indie::raylib::Window::getHeight());

        return (windowDim * percent / 100.f);
    }
} // namespace indie::tools