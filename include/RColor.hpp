/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** rayStructs
*/

#ifndef RCOLOR_HPP_
#define RCOLOR_HPP_

#define RBLACK (rColor){ 0, 0, 0, 255 }
#define RRED (rColor){ 255, 0, 0, 255 }
#define RBLUE (rColor){ 0, 0, 255, 255 }
#define RGREEN (rColor){ 0, 255, 0, 255 }
#define RWHITE (rColor){ 255, 255, 255, 255 }

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} rColor;

#endif /* !RAYSTRUCTS_HPP_ */
