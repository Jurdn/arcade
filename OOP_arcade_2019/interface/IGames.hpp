/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Igame.hpp
*/

#ifndef __IGAME__HPP__
#define __IGAME__HPP__

#include <string>
#include <vector>
#include "Values.hpp"

class IGames {
public:
    virtual void initGame(void) = 0;
    virtual bool processInput(int key) = 0;
    virtual bool checkEnd(void) = 0;
    virtual std::string const getName() = 0;
    virtual std::vector<std::string> const &getMap(void) = 0;
    virtual int getScore() = 0;
    virtual void restart() = 0;
};

#endif