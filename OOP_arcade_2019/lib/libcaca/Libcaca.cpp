/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Libcaca.cpp
*/

#include "Libcaca.hpp"
#include "StatsLibcaca.hpp"

Libcaca::~Libcaca()
{

}

Libcaca::Libcaca()
{

}

void Libcaca::initGraphic(Player &pl)
{
    _dp = caca_create_display(caca_create_canvas(CACA_WIDTH, CACA_HEIGHT));
    _cv = caca_get_canvas(_dp);
    caca_set_display_title(_dp, "BAAAH Gaming");
    caca_set_color_ansi(_cv, CACA_BLACK, CACA_WHITE);

    _player = pl;
}

void Libcaca::showGame(std::vector<std::string> const &map, int score, std::string const &gameName)
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

    caca_clear_canvas(_cv);
    caca_put_str(_cv, 5, 7, "Score:");
    caca_put_str(_cv, 5, 9, std::to_string(score).c_str());
    for (int i = 0; i != mapCopy.size(); i++) {
        caca_put_str(_cv, CACA_WIDTH / 2 - mapCopy.at(i).length() / 2, 10 + i, mapCopy.at(i).c_str());
    }

    caca_refresh_display(_dp);
    std::this_thread::sleep_for(std::chrono::milliseconds(175));
}

int Libcaca::getInput()
{
    caca_get_event(this->_dp, CACA_EVENT_KEY_PRESS, &this->_ev, 100000);
    if (caca_get_event_type(&this->_ev) == CACA_EVENT_KEY_PRESS) {
        if (caca_get_event_key_ch(&this->_ev) == 'd')
            return ('d');
        else if (caca_get_event_key_ch(&this->_ev) == 'q')
            return ('q');
        else if (caca_get_event_key_ch(&this->_ev) == 'z')
            return ('z');
        else if (caca_get_event_key_ch(&this->_ev) == 's')
            return ('s');
        else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_ESCAPE)
            return ('p');
        else if (caca_get_event_key_ch(&this->_ev) == 'i' || caca_get_event_key_ch(&this->_ev) == 'o')
            return (OTHER_GAME);
        else if (caca_get_event_key_ch(&this->_ev) == 'r')
            return (RESTART_GAME);
        else if (caca_get_event_key_ch(&this->_ev) == 'm')
            return (BACK_MENU_GAME);
        else if (caca_get_event_key_ch(&this->_ev) == 'e')
            return (EXIT_GAME);
        else if (caca_get_event_key_ch(&this->_ev) == 'g')
            return (NEXT_LIB);
        else if (caca_get_event_key_ch(&this->_ev) == 'f')
            return (PREVIOUS_LIB);
    }
    return (0);
}

int Libcaca::showPause(void)
{
    int cursorPos = PAUSE_RESUME;

    while (1) {
        caca_clear_canvas(_cv);

        if (cursorPos == PAUSE_RESUME)
            caca_put_str(_cv, CACA_WIDTH / 2 - 15, 15, ">");
        else if (cursorPos == PAUSE_MENU)
            caca_put_str(_cv, CACA_WIDTH / 2 - 15, 17, ">");
        else if (cursorPos == PAUSE_EXIT)
            caca_put_str(_cv, CACA_WIDTH / 2 - 15, 19, ">");

        caca_put_str(_cv, CACA_WIDTH / 2 - 6, 10, "Pause");
        caca_put_str(_cv, CACA_WIDTH / 2 - 6, 15, "Resume");
        caca_put_str(_cv, CACA_WIDTH / 2 - 6, 17, "Menu");
        caca_put_str(_cv, CACA_WIDTH / 2 - 6, 19, "Exit");

        caca_get_event(this->_dp, CACA_EVENT_KEY_PRESS, &this->_ev, 100000);
        if (caca_get_event_type(&this->_ev) == CACA_EVENT_KEY_PRESS) {
            if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_UP) {
                cursorPos -= 1;
                if (cursorPos < PAUSE_RESUME)
                    cursorPos = PAUSE_EXIT;
            } else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_DOWN) {
                cursorPos += 1;
                if (cursorPos > PAUSE_EXIT)
                    cursorPos = PAUSE_RESUME;
            } else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_RETURN) {
                return (cursorPos);
            }
        }
        caca_refresh_display(_dp);
    }
    return (PAUSE_RESUME);
}

int Libcaca::showMenu(Player &pl)
{
    StatsLibcaca slc;
    int cursorPos = CURSOR_GAME1;

    caca_clear_canvas(_cv);
    while (1) {
        caca_clear_canvas(_cv);
        caca_put_str(_cv, CACA_WIDTH / 2 - 6, 5, "BAAAH Gaming");

        if (cursorPos == CURSOR_GAME1)
            caca_put_str(_cv, CACA_WIDTH / 2 - 20, 15, ">");
        else if (cursorPos == CURSOR_GAME2)
            caca_put_str(_cv, CACA_WIDTH / 2 - 20, 18, ">");
        else if (cursorPos == CURSOR_STATS)
            caca_put_str(_cv, CACA_WIDTH / 2 - 20, 21, ">");
        else if (cursorPos == CURSOR_EXIT)
            caca_put_str(_cv, CACA_WIDTH / 2 - 20, 30, ">");

        caca_put_str(_cv, CACA_WIDTH / 2 - 3, 15, "Pacman");
        caca_put_str(_cv, CACA_WIDTH / 2 - 4, 18, "Nibbler");
        caca_put_str(_cv, CACA_WIDTH / 2 - 5, 21, "Statistics");
        caca_put_str(_cv, CACA_WIDTH / 2 - 2, 30, "Exit");

        caca_put_str(_cv, 5, 7, "Score:");
        caca_put_str(_cv, 5, 9, std::to_string(pl._totalScore).c_str());

        caca_get_event(this->_dp, CACA_EVENT_KEY_PRESS, &this->_ev, 100000);
        if (caca_get_event_type(&this->_ev) == CACA_EVENT_KEY_PRESS) {
            if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_UP) {
                cursorPos -= 1;
                if (cursorPos < CURSOR_GAME1)
                    cursorPos = CURSOR_EXIT;
            } else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_DOWN) {
                cursorPos += 1;
                if (cursorPos > CURSOR_EXIT)
                    cursorPos = CURSOR_GAME1;
            } else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_RETURN) {
                if (cursorPos == CURSOR_GAME1)
                    return (MENU_PLAY_PACMAN);
                if (cursorPos == CURSOR_GAME2)
                    return (MENU_PLAY_NIBBLER);
                if (cursorPos == CURSOR_STATS)
                    slc.showStats(pl, this->_cv, this->_dp);
                if (cursorPos == CURSOR_EXIT)
                    return (MENU_CLOSE_WINDOW);
            } else if (caca_get_event_key_ch(&this->_ev) == 'f')
                return (PREVIOUS_LIB);
            else if (caca_get_event_key_ch(&this->_ev) == 'g')
                return (NEXT_LIB);
            else if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_F9)
                return (MENU_CLOSE_WINDOW);
        }
        caca_refresh_display(_dp);
    }
    return (MENU_CLOSE_WINDOW);
}

void Libcaca::showLose(int score)
{
    caca_clear_canvas(_cv);
    caca_put_str(_cv, CACA_WIDTH / 2 - 4, CACA_HEIGHT / 2 - 1, "LOOSER!");
    caca_put_str(_cv, CACA_WIDTH / 2 - 4, CACA_HEIGHT / 2 + 1, std::to_string(score).c_str());
    caca_refresh_display(_dp);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void Libcaca::showWin(int score)
{
    caca_clear_canvas(_cv);
    caca_put_str(_cv, CACA_WIDTH / 2 - 4, CACA_HEIGHT / 2 - 1, "YOU WON!");
    caca_put_str(_cv, CACA_WIDTH / 2 - 4, CACA_HEIGHT / 2 + 1, std::to_string(score).c_str());
    caca_refresh_display(_dp);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void Libcaca::exitGraphics(void)
{
    caca_free_canvas(_cv);
    caca_free_display(_dp);
}

std::string Libcaca::getLibName(void)
{
    std::string name = "libcaca";
    return (name);
}