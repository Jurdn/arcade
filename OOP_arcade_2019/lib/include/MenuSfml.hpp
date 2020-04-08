/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** MenuSfml.hpp
*/

#ifndef __NCURSES__HPP__
#define __NCURSES__HPP__

#include "Sfml.hpp"

class MenuSfml {
public:
    MenuSfml();
    ~MenuSfml();

    int printMenuSFML(SFML &, Player &);

    void initMenuGraphics(SFML &);

    int handleEventMenu(sf::Event const &, SFML &);
    void moveCursorMenu(SFML &);

    void changePacmanColor(SFML &);
    void changeNibblerColor(SFML &);
    void changeStatsColor(SFML &);
    void changeExitColor(SFML &);

    void modifyColor(void);

    sf::Text _textBaaah;
    sf::Text _textGaming;
    sf::Text _textPacman;
    sf::Text _textNibbler;
    sf::Text _textStats;
    sf::Text _textExit;

    sf::Text _textScoreLabel;
    sf::Text _textScore;

    sf::Text _textCursor;

    sf::Color _color;

    int _maxColor;
    int _cursorPos;
    Player _player;
};

#endif