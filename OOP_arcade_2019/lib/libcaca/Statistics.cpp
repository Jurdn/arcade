/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** statistics.cpp
*/

#include "StatsLibcaca.hpp"

StatsLibcaca::~StatsLibcaca()
{

}

StatsLibcaca::StatsLibcaca()
{

}

void StatsLibcaca::showStats(Player &pl, caca_canvas_t *cv, caca_display_t *dp)
{
    int cursorPos = CURSOR_GAME1;

    while (1) {
        caca_clear_canvas(cv);
        caca_put_str(cv, CACA_WIDTH / 2 - 6, 5, "Statistics");
        caca_put_str(cv, CACA_WIDTH / 2 - 10, 7, "Player:");
        caca_put_str(cv, CACA_WIDTH / 2 + 10, 7, pl._playerName.c_str());

        caca_put_str(cv, CACA_WIDTH / 2 - 15, 10, "Nibbler");
        caca_put_str(cv, CACA_WIDTH / 2 + 15, 10, "Pacman");

        caca_put_str(cv, CACA_WIDTH / 2 - 15, 13, std::to_string(pl._scoreNibbler.at(4)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 - 15, 15, std::to_string(pl._scoreNibbler.at(3)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 - 15, 17, std::to_string(pl._scoreNibbler.at(2)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 - 15, 19, std::to_string(pl._scoreNibbler.at(1)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 - 15, 21, std::to_string(pl._scoreNibbler.at(0)).c_str());

        caca_put_str(cv, CACA_WIDTH / 2 + 15, 13, std::to_string(pl._scorePacman.at(4)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 + 15, 15, std::to_string(pl._scorePacman.at(3)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 + 15, 17, std::to_string(pl._scorePacman.at(2)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 + 15, 19, std::to_string(pl._scorePacman.at(1)).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 + 15, 21, std::to_string(pl._scorePacman.at(0)).c_str());

        caca_put_str(cv, CACA_WIDTH / 2 - 6, 30, "Total Score:");
        caca_put_str(cv, CACA_WIDTH / 2 - 6, 32, std::to_string(pl._totalScore).c_str());
        caca_put_str(cv, CACA_WIDTH / 2 - 6, 34, "Press ESC to go back to the menu");

        caca_get_event(dp, CACA_EVENT_KEY_PRESS, &this->_ev, 100000);
        if (caca_get_event_type(&this->_ev) == CACA_EVENT_KEY_PRESS) {
            if (caca_get_event_key_ch(&this->_ev) == CACA_KEY_ESCAPE)
                return;
        }
        caca_refresh_display(dp);
    }
}