/*
** EPITECH PROJECT, 2020
** Main.cpp
** File description:
** Main
*/

#include "Nibbler.hpp"

extern "C" IGames *getInterface(void)
{
    return new Nibbler;
}