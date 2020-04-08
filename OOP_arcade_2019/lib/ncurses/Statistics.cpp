/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** statistics.cpp
*/

#include "StatsNcurses.hpp"

StatsNcurses::~StatsNcurses()
{

}

StatsNcurses::StatsNcurses()
{
    _score = 0;
}

void StatsNcurses::drawStats(Ncurses &nc, std::vector<int> &scoreNibbler, std::vector<int> &scorePacman)
{
    nc.printBoldText(5, (COLS / 2), "Statistics");
    nc.printNormalText(7, (COLS / 2) - 7, "Player:");
    nc.printUnderlinedText(7, (COLS / 2) + 7, nc._player._playerName);
    nc.printUnderlinedText(35, (COLS / 2), "Total Score:");
    nc.printBoldText(37, (COLS / 2), std::to_string(nc._player._totalScore));
    nc.printNormalText(40, (COLS / 2), "Press exit to go back to the menu.");

    nc.printUnderlinedText(11, (COLS / 2) - 20, "Nibbler");

    nc.printNormalText(14, (COLS / 2) - 20, std::to_string(scoreNibbler.at(4)));
    nc.printNormalText(16, (COLS / 2) - 20, std::to_string(scoreNibbler.at(3)));
    nc.printNormalText(18, (COLS / 2) - 20, std::to_string(scoreNibbler.at(2)));
    nc.printNormalText(20, (COLS / 2) - 20, std::to_string(scoreNibbler.at(1)));
    nc.printNormalText(22, (COLS / 2) - 20, std::to_string(scoreNibbler.at(0)));

    nc.printUnderlinedText(11, (COLS / 2) + 20, "Pacman");

    nc.printNormalText(14, (COLS / 2) + 20, std::to_string(scorePacman.at(4)));
    nc.printNormalText(16, (COLS / 2) + 20, std::to_string(scorePacman.at(3)));
    nc.printNormalText(18, (COLS / 2) + 20, std::to_string(scorePacman.at(2)));
    nc.printNormalText(20, (COLS / 2) + 20, std::to_string(scorePacman.at(1)));
    nc.printNormalText(22, (COLS / 2) + 20, std::to_string(scorePacman.at(0)));
}

int StatsNcurses::handleEvent(int ch)
{
    if (ch == 27)
        return (MENU_STATS);
    return (0);
}

int StatsNcurses::printStats(Ncurses &nc, std::vector<int> &scoreNibbler, std::vector<int> &scorePacman)
{
    int ch = 0;
    int ret_event = 0;

    clear();
    while (1) {
        ret_event = StatsNcurses::handleEvent(ch);
        if (ret_event == MENU_STATS)
            return (0);

        StatsNcurses::drawStats(nc, scoreNibbler, scorePacman);

        refresh();
        ch = getch();
        clear();
    }
    clear();
    endwin();
    return (MENU_CLOSE_WINDOW);
}