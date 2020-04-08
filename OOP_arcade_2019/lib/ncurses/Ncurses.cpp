/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ncurses.cpp
*/

#include "Ncurses.hpp"
#include "MenuNcurses.hpp"

Ncurses::~Ncurses()
{

}

Ncurses::Ncurses()
{

}

void Ncurses::initGraphic(Player &pl)
{
    initscr();
    _win = newwin(21, 21, LINES / 2 - 10, COLS / 2 - 10);
    refresh();
    //nodelay(_win, true);
    //halfdelay(5);
    wtimeout(_win, 0);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    clear();

    _player = pl;
}

void Ncurses::showGame(std::vector<std::string> const &map, int score, std::string const &gameName)
{
    std::vector<std::string> mapCopy = map;

    for (int index = 0; index != mapCopy.size(); index++) {
        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), '|', '#');
        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), '=', '#');

        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), 'N', 'O');
        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), 'S', 'O');
        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), 'W', 'O');
        std::replace(mapCopy.at(index).begin(), mapCopy.at(index).end(), 'E', 'O');
    }

    clear();
    wclear(_win);
    printUnderlinedText(5, 2, "Score:");
    printBoldText(7, 2, std::to_string(score));
    for (int i = 0; i != mapCopy.size(); i++) {
        mvwprintw(_win, i, 0, "%s", mapCopy[i].c_str());
    }
    refresh();
    wrefresh(_win);
}

int Ncurses::getInput()
{
    flushinp();
    std::this_thread::sleep_for(std::chrono::milliseconds(175));
    int key = wgetch(_win);
    if (key == 27)
        return ('p');
    else if (key == 'z')
        return ('z');
    else if (key == 'q')
        return ('q');
    else if (key == 's')
        return ('s');
    else if (key == 'd')
        return ('d');
    else if (key == 'i' || key == 'o')
        return (OTHER_GAME);
    else if (key == 'r')
        return (RESTART_GAME);
    else if (key == 'm')
        return (BACK_MENU_GAME);
    else if (key == 'e')
        return (EXIT_GAME);
    else if (key == 'g')
        return (NEXT_LIB);
    else if (key == 'f')
        return (PREVIOUS_LIB);
    return (0);
}

int Ncurses::showPause(void)
{
    int ch = 0;
    int cursorPos = PAUSE_RESUME;
    WINDOW *boxGame = subwin(stdscr, 28, 37, 8, COLS / 2 - 16);

    clear();
    while (1) {
        if (ch == KEY_UP) {
            cursorPos -= 1;
            if (cursorPos < PAUSE_RESUME)
                cursorPos = PAUSE_EXIT;
        } else if (ch == KEY_DOWN) {
            cursorPos += 1;
            if (cursorPos > PAUSE_EXIT)
                cursorPos = PAUSE_RESUME;
        } else if (ch == 10)
            return (cursorPos);

        if (cursorPos == PAUSE_RESUME) {
            printNormalText(20, (COLS / 2) - 9, ">");
            printBoldText(20, (COLS / 2), "Resume");
        } else
            printNormalText(20, (COLS / 2), "Resume");
        if (cursorPos == PAUSE_MENU) {
            printNormalText(25, (COLS / 2) - 9, ">");
            printBoldText(25, (COLS / 2), "Menu");
        } else
            printNormalText(25, (COLS / 2), "Menu");
        if (cursorPos == PAUSE_EXIT) {
            printNormalText(30, (COLS / 2) - 9, ">");
            printBoldText(30, (COLS / 2), "Exit");
        } else
            printNormalText(30, (COLS / 2), "Exit");
        wborder(boxGame, '|', '|', '-', '-', '+', '+', '+', '+');
        wrefresh(boxGame);
        printUnderlinedText(10, (COLS / 2), "Pause");

        refresh();
        ch = getch();
        clear();
    }
    return (PAUSE_RESUME);
}

int Ncurses::showMenu(Player &pl)
{
    MenuNcurses mn;

    return (mn.printMenu(*this, pl));
}

void Ncurses::showLose(int score)
{
    clear();
    printNormalText((LINES / 2) - 1, (COLS / 2), "LOOSER!");
    printNormalText((LINES / 2) + 1, (COLS / 2), std::to_string(score));
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void Ncurses::showWin(int score)
{
    clear();
    printNormalText((LINES / 2) - 1, (COLS / 2), "YOU WON!");
    printNormalText((LINES / 2) + 1, (COLS / 2), std::to_string(score));
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void Ncurses::exitGraphics(void)
{
    clear();
    endwin();
}

std::string Ncurses::getLibName(void)
{
    std::string name = "ncurses";
    return (name);
}

void Ncurses::printBoldText(int x, int y, std::string const &text)
{
    attron(A_STANDOUT);
    mvprintw(x, y, text.c_str());
    attroff(A_STANDOUT);
}

void Ncurses::printUnderlinedText(int x, int y, std::string const &text)
{
    attron(A_UNDERLINE);
    mvprintw(x, y, text.c_str());
    attroff(A_UNDERLINE);
}

void Ncurses::printNormalText(int x, int y, std::string const &text)
{
    attron(A_NORMAL);
    mvprintw(x, y, text.c_str());
    attroff(A_NORMAL);
}