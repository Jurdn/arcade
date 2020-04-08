/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Libcaca.hpp
*/

#ifndef __LIBCACA__HPP__
#define __LIBCACA__HPP__

#include <caca.h>
#include <chrono>
#include <thread>
#include "IGraphics.hpp"

class Libcaca : public IGraphics {
public:
    Libcaca();
    ~Libcaca();

    void initGraphic(Player &);
    void showGame(std::vector<std::string> const &map, int score, std::string const &);
    int showPause(void);
    int getInput();
    int showMenu(Player &);
    void showWin(int);
    void showLose(int);
    void exitGraphics(void);
    std::string getLibName(void);

    caca_canvas_t *_cv;
    caca_display_t *_dp;
    caca_event_t _ev;

    Player _player;
};

#endif