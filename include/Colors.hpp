/**
 * @file Colors.hpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief Colors used for bomberman
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INDIE_COLORS_HPP_
#define INDIE_COLORS_HPP_

#include <raylib.h>

#define BLUECOLOR        \
    CLITERAL(Color)      \
    {                    \
        0, 121, 241, 255 \
    }

#define GREENCOLOR      \
    CLITERAL(Color)     \
    {                   \
        0, 228, 48, 255 \
    }

#define MAGENTACOLOR     \
    CLITERAL(Color)      \
    {                    \
        255, 0, 255, 255 \
    }

#define YELLOWCOLOR      \
    CLITERAL(Color)      \
    {                    \
        253, 249, 0, 255 \
    }

#define REDCOLOR         \
    CLITERAL(Color)      \
    {                    \
        230, 41, 55, 255 \
    }

#define GREENPLAYERCOLOR  \
    CLITERAL(Color)       \
    {                     \
        175, 213, 170, 80 \
    }

#define YELLOWPLAYERCOLOR \
    CLITERAL(Color)       \
    {                     \
        245, 212, 145, 80 \
    }

#define REDPLAYERCOLOR  \
    CLITERAL(Color)     \
    {                   \
        209, 73, 91, 80 \
    }

#define BLUEPLAYERCOLOR   \
    CLITERAL(Color)       \
    {                     \
        163, 231, 252, 80 \
    }

#endif