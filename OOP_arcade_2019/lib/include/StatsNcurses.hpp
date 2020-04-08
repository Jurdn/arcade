/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** StatsNcurses.hpp
*/

#ifndef __STATSCURSES__HPP__
#define __STATSCURSES__HPP__

#include "Ncurses.hpp"

class StatsNcurses {
public:
    StatsNcurses();
    ~StatsNcurses();

    void drawStats(Ncurses &, std::vector<int> &, std::vector<int> &);
    int printStats(Ncurses &, std::vector<int> &, std::vector<int> &);
    int handleEvent(int);

    int _score;
};

#endif
