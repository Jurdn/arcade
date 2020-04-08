/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Menu.cpp
*/

#include "MenuNcurses.hpp"
#include "StatsNcurses.hpp"

MenuNcurses::~MenuNcurses()
{

}

MenuNcurses::MenuNcurses()
{
    _cursorPos = CURSOR_GAME1;
    _score = 0;
}

void MenuNcurses::drawMenu(Ncurses &nc, int totalScore)
{
    _boxBorder = subwin(stdscr, 5, 26, 3, COLS /2 - 7);
    wborder(_boxBorder, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(_boxBorder);

    nc.printBoldText(5, (COLS / 2), "BAAAH Gaming");
    nc.printUnderlinedText(5, 2, "Score:");
    nc.printBoldText(7, 2, std::to_string(totalScore));
    
    if (_cursorPos == CURSOR_GAME1) {
        nc.printNormalText(20, (COLS / 2) - 10, ">");
        nc.printUnderlinedText(20, (COLS / 2), "Pacman");
    } else
        nc.printNormalText(20, (COLS / 2), "Pacman");
    if (_cursorPos == CURSOR_GAME2) {
        nc.printNormalText(25, (COLS / 2) - 10, ">");
        nc.printUnderlinedText(25, (COLS / 2), "Nibbler");
    } else
        nc.printNormalText(25, (COLS / 2), "Nibbler");
    if (_cursorPos == CURSOR_STATS) {
        nc.printNormalText(30, (COLS / 2) - 10, ">");
        nc.printUnderlinedText(30, (COLS / 2), "Statistics");
    } else
        nc.printNormalText(30, (COLS / 2), "Statistics");
    if (_cursorPos == CURSOR_EXIT) {
        nc.printNormalText(40, (COLS / 2) - 10, ">");
        nc.printUnderlinedText(40, (COLS / 2), "Exit");
    } else
        nc.printNormalText(40, (COLS / 2), "Exit");
    attron(A_NORMAL);
}

int MenuNcurses::handleEvent(int ch)
{
    if (ch == KEY_F(9)) {
        clear();
        endwin();
        return (CLOSE_WINDOW);
    } else if (ch == KEY_F(3)) {
        clear();
        endwin();
        return (MENU_PREVIOUS_GAME);
    } else if (ch == KEY_F(4)) {
        clear();
        endwin();
        return (MENU_NEXT_GAME);
    } else if (ch == 'f') {
        clear();
        endwin();
        return (PREVIOUS_LIB);
    } else if (ch == 'g') {
        clear();
        endwin();
        return (NEXT_LIB);
    } else if (ch == 10) {
        clear();
        endwin();
        return (OPT_SELECTED);
    } else if (ch == KEY_UP) {
        _cursorPos -= 1;
        if (_cursorPos < CURSOR_GAME1)
            _cursorPos = CURSOR_EXIT;
    } else if (ch == KEY_DOWN) {
        _cursorPos += 1;
        if (_cursorPos > CURSOR_EXIT)
            _cursorPos = CURSOR_GAME1;
    }
    return (0);
}

int MenuNcurses::printMenu(Ncurses &nc, Player &pl)
{
    int ch = 0;
    int ret_event = 0;
    StatsNcurses sn;

    clear();
    while (1) {
        ret_event = MenuNcurses::handleEvent(ch);
        if (ret_event == CLOSE_WINDOW)
            return (MENU_CLOSE_WINDOW);
        else if (ret_event == NEXT_LIB)
            return (NEXT_LIB);
        else if (ret_event == PREVIOUS_LIB)
            return (PREVIOUS_LIB);
        else if (ret_event == MENU_NEXT_GAME)
            return (MENU_NEXT_GAME);
        else if (ret_event == MENU_PREVIOUS_GAME)
            return (MENU_PREVIOUS_GAME);
        else if (ret_event == OPT_SELECTED) {
            if (_cursorPos == CURSOR_GAME1)
                return (MENU_PLAY_PACMAN);
            else if (_cursorPos == CURSOR_GAME2)
                return (MENU_PLAY_NIBBLER);
            else if (_cursorPos == CURSOR_STATS)
                sn.printStats(nc, nc._player._scoreNibbler, nc._player._scorePacman);
            else if (_cursorPos == CURSOR_EXIT)
                return (MENU_CLOSE_WINDOW);
        }

        MenuNcurses::drawMenu(nc, nc._player.getTotalScore());

        refresh();
        ch = getch();
        clear();
    }
    clear();
    endwin();
    return (MENU_CLOSE_WINDOW);
}