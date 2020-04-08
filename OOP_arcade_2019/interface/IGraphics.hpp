/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IGraphic.hpp
*/

#ifndef __IGRAPHIC__HPP__
#define __IGRAPHIC__HPP__

#include "Values.hpp"
#include "Player.hpp"

class IGraphics {
public:
    virtual void initGraphic(Player &) = 0;

    virtual void showGame(std::vector<std::string> const &, int, std::string const &) = 0;
    // RETURN VALUE:
    //
    //  -1 if player left the game
    //   0 if player goes back to menu
    // > 0 == player score

    virtual int showPause(void) = 0;
    // RETURN VALUE:
    //
    // RESUME if player continues the game
    // MENU   if player goes back to menu
    // EXIT   if player lefts the game

    virtual int showMenu(Player &) = 0;
    // RETURN VALUE:
    //
    // NIBBLER if player selects nibbler
    // PACMAN  if player selects pacman
    // STATS   if player selects stats
    // EXIT    if player lefts the game

    virtual void showWin(int) = 0;
    virtual void showLose(int) = 0;

    virtual int getInput() = 0;

    virtual std::string getLibName(void) = 0;

    virtual void exitGraphics(void) = 0;
};

#endif