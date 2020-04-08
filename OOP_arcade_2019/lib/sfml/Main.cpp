/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main.cpp
*/

#include "Sfml.hpp"

extern "C" IGraphics *getInterface(void)
{
    return new SFML;
}