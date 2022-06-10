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
    class Tools {
      public:
        Tools();
        ~Tools();

        static float getPercentage(float percent, bool isWidth);
    };
} // namespace indie::tools

#endif /* !TOOLS_HPP_ */
