/**
 * @file Tools.cpp
 * @author Johan (johan.chrillesen@epitech.eu)
 * @brief Useful functions
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
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