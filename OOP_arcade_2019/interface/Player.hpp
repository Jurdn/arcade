/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** player.cpp
*/

#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#define NEW_PLAYER 55
#define OLD_PLAYER 56
#define SCORE_PATH "./score.txt"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Player {
public:
    Player();
    Player(std::string const &);
    ~Player();

    void getFileContent(void);
    void getPlayerStats(void);

    void loadPlayer(void);

    void saveFile(void);

    bool orderFunction(int, int);
    void addScore(int, std::string const &);
    void refreshTotalScore(void);

    int getTotalScore(void);
    std::vector<int> getScoreNibbler(void);
    std::vector<int> getScorePacman(void);

    std::string _playerName;
    std::string _contentFile;

    int _totalScore;

    std::vector<int> _scoreNibbler;
    std::vector<int> _scorePacman;
};

#endif