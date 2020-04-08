/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Main.cpp
*/

#include "Libcaca.hpp"

extern "C" IGraphics *getInterface(void)
{
    return new Libcaca;
}