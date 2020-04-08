/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Ncurses.hpp
*/

#ifndef __NCURSES__HPP__
#define __NCURSES__HPP__

#include <ncurses.h>
#include <chrono>
#include <thread>
#include "IGraphics.hpp"

class Ncurses : public IGraphics {
public:
    Ncurses();
    ~Ncurses();

    void initGraphic(Player &);
    virtual void showGame(std::vector<std::string> const &map, int score, std::string const &);
    virtual int getInput();
    int showPause(void);
    int showMenu(Player &);
    void showWin(int);
    void showLose(int);
    void exitGraphics(void);
    std::string getLibName(void);

    void printNormalText(int, int, std::string const &);
    void printUnderlinedText(int, int, std::string const &);
    void printBoldText(int, int, std::string const &);

    Player _player;
    WINDOW *_win;
};

#endif