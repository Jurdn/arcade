/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main.cpp
*/

#include "Ncurses.hpp"

extern "C" IGraphics *getInterface(void)
{
    return new Ncurses;
}