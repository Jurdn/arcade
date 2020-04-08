/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Main.cpp
*/

#include "Pacman.hpp"

extern "C" IGames *getInterface(void)
{
    return new Pacman;
}