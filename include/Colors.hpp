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

/**
 * @brief Macro for blue
 * 
 */
#define BLUECOLOR        \
    CLITERAL(Color)      \
    {                    \
        0, 121, 241, 255 \
    }
/**
 * @brief Macro for green
 * 
 */
#define GREENCOLOR      \
    CLITERAL(Color)     \
    {                   \
        0, 228, 48, 255 \
    }
/**
 * @brief Macro for magenta
 * 
 */
#define MAGENTACOLOR     \
    CLITERAL(Color)      \
    {                    \
        255, 0, 255, 255 \
    }
/**
 * @brief Macro for yellow
 * 
 */
#define YELLOWCOLOR      \
    CLITERAL(Color)      \
    {                    \
        253, 249, 0, 255 \
    }
/**
 * @brief Macro for red
 * 
 */
#define REDCOLOR         \
    CLITERAL(Color)      \
    {                    \
        230, 41, 55, 255 \
    }
/**
 * @brief Macro for player green
 * 
 */
#define GREENPLAYERCOLOR  \
    CLITERAL(Color)       \
    {                     \
        175, 213, 170, 80 \
    }
/**
 * @brief Macro for player yellow
 * 
 */
#define YELLOWPLAYERCOLOR \
    CLITERAL(Color)       \
    {                     \
        245, 212, 145, 80 \
    }
/**
 * @brief Macro for player red
 * 
 */
#define REDPLAYERCOLOR  \
    CLITERAL(Color)     \
    {                   \
        209, 73, 91, 80 \
    }
/**
 * @brief Macro for player blue
 * 
 */
#define BLUEPLAYERCOLOR   \
    CLITERAL(Color)       \
    {                     \
        163, 231, 252, 80 \
    }

#endif