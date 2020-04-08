/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** StatsLibcaca.hpp
*/

#ifndef __STATSLIBCACA__HPP__
#define __STATSLIBCACA__HPP__

#include "Libcaca.hpp"

class StatsLibcaca {
public:
    StatsLibcaca();
    ~StatsLibcaca();

    void showStats(Player &, caca_canvas_t *, caca_display_t *);

    caca_event_t _ev;
};

#endif