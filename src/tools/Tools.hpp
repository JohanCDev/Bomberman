/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Tools
*/

#ifndef TOOLS_HPP_
#define TOOLS_HPP_

namespace indie::tools
{
    /**
     * @brief Class for some useful tools
     * 
     */
    class Tools {
      public:
        /**
         * @brief Construct a new Tools object
         * 
         */
        Tools();
        /**
         * @brief Destroy the Tools object
         * 
         */
        ~Tools();
        /**
        * @brief Get the position of the center (for alignement)
        * 
        * @param percent Percentage for alignement
        * @param isWidth True for width, False for height
        * @return float Position of the center alignement
        */
        static float getPercentage(float percent, bool isWidth);
    };
} // namespace indie::tools

#endif /* !TOOLS_HPP_ */
