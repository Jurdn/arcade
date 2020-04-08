/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** stats.cpp
*/

#ifndef __STATSSFML__HPP__
#define __STATSSFML__HPP__

#include "Sfml.hpp"

class StatsSFML {
public:
    StatsSFML();
    ~StatsSFML();

    int printStatsSFML(SFML &, std::vector<int> &, std::vector<int> &);
    void initStatsGraphics(SFML &);
    int handleEventStats(sf::Event const &, SFML &);
    void modifyColor(void);

    sf::Text _textStats;

    sf::Text _textScoreNibbler;
    sf::Text _textScorePacman;
    
    // sf::Text _textScorePacman1;
    // sf::Text _textScorePacman2;
    // sf::Text _textScorePacman3;
    // sf::Text _textScorePacman4;
    // sf::Text _textScorePacman5;

    // sf::Text _textScoreNibbler1;
    // sf::Text _textScoreNibbler2;
    // sf::Text _textScoreNibbler3;
    // sf::Text _textScoreNibbler4;
    // sf::Text _textScoreNibbler5;

    // sf::Text _textPlayerPhrase;
    // sf::Text _textPlayer;

    // sf::Text _textScore;
    // sf::Text _textLabel;

    sf::Color _color;

    int _maxColor;
    int _globalScore;
};

#endif
