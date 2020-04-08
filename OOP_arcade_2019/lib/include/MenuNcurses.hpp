/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** MenuNcurses.hpp
*/

#ifndef __MENUNCURSES__HPP__
#define __MENUNCURSES__HPP__

#include "Ncurses.hpp"

class MenuNcurses {
public:
    MenuNcurses();
    ~MenuNcurses();

    void drawMenu(Ncurses &, int);
    int printMenu(Ncurses &, Player &);
    int handleEvent(int);

    WINDOW *_boxBorder;
    int _cursorPos;
    int _score;
};

#endif