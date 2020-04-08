/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player()
{

}

Player::Player(std::string const &playerName) : _playerName(playerName), _totalScore(0)
{

}

Player::~Player()
{

}

bool Player::orderFunction(int i, int j)
{
    return (i > j);
}

void Player::addScore(int newScore, std::string const &game)
{
    if (game.compare("pacman") == 0) {
        for (int i = 0; i < _scorePacman.size(); i++) {
            if (_scorePacman.at(i) < newScore) {
                _scorePacman[i] = newScore;
                std::sort(_scorePacman.begin(), _scorePacman.end());
                return;
            }
        }
        std::sort(_scorePacman.begin(), _scorePacman.end());
    } else if (game.compare("nibbler") == 0) {
        for (int i = 0; i < _scoreNibbler.size(); i++) {
            if (_scoreNibbler.at(i) < newScore) {
                _scoreNibbler[i] = newScore;
                std::sort(_scoreNibbler.begin(), _scoreNibbler.end());
                return;
            }
        }
        std::sort(_scoreNibbler.begin(), _scoreNibbler.end());
    }
    this->refreshTotalScore();
}

void Player::getFileContent(void)
{
    char c;
    std::ifstream my_file(SCORE_PATH, std::ios::in);

    if (my_file) {
        while (my_file.get(c)) {
            _contentFile += c;
        }
    }
}

void Player::getPlayerStats(void)
{
    size_t pos = _contentFile.find(_playerName);
    size_t posPlayerName = pos;
    size_t endPos;
    std::string stats;
    size_t end;
    size_t findComma;

    if (pos != std::string::npos) {
        pos += _playerName.length() + 1;
        end = (_contentFile.substr(pos)).find(".");
        endPos = end;
        stats = _contentFile.substr(pos, end);
        for (int i = 0; i < 4; i++) {
            findComma = stats.find(",");
            _scoreNibbler.push_back(atoi(stats.substr(0, findComma).c_str()));
            stats = stats.substr(findComma + 1);
        }
        findComma = stats.find("\n");
        _scoreNibbler.push_back(atoi(stats.substr(0, findComma).c_str()));
        stats = stats.substr(findComma + 1);
        for (int i = 0; i < 4; i++) {
            findComma = stats.find(",");
            _scorePacman.push_back(atoi(stats.substr(0, findComma).c_str()));
            stats = stats.substr(findComma + 1);
        }
        findComma = stats.find("\n");
        _scorePacman.push_back(atoi(stats.substr(0, findComma).c_str()));
        stats = stats.substr(findComma + 1);
        _contentFile.erase(posPlayerName, endPos + _playerName.length() + 1 + 1 + 1);
    } else {
        _scorePacman.push_back(0);
        _scorePacman.push_back(0);
        _scorePacman.push_back(0);
        _scorePacman.push_back(0);
        _scorePacman.push_back(0);
        _scoreNibbler.push_back(0);
        _scoreNibbler.push_back(0);
        _scoreNibbler.push_back(0);
        _scoreNibbler.push_back(0);
        _scoreNibbler.push_back(0);
    }
    for (int i = 0; i < _scorePacman.size(); i++) {
        _totalScore += _scorePacman.at(i);
        _totalScore += _scoreNibbler.at(i);
    }
    
}

void showStats(std::vector<int> un)
{
    for (int i = 0; i < un.size(); i++) {
        std::cout << un.at(i) << std::endl;
    }
}

void Player::loadPlayer(void)
{
    Player::getFileContent();
    Player::getPlayerStats();
}

void Player::saveFile(void)
{
    std::ofstream file(SCORE_PATH);

    file << _contentFile;
    file << _playerName << std::endl;
    for (int i = 0; i < _scoreNibbler.size(); i++) {
        file << _scoreNibbler.at(i);
        if (i != _scoreNibbler.size() - 1) {
            file << ",";
        } else {
            file << std::endl;
        }
    }
    for (int j = 0; j < _scorePacman.size(); j++) {
        file << _scorePacman.at(j);
        if (j != _scorePacman.size() - 1) {
            file << ",";
        } else {
            file << std::endl;
        }
    }
    file << "." << std::endl;
    file.close();
}

void Player::refreshTotalScore(void)
{
    _totalScore = _scorePacman.at(0) + _scorePacman.at(1) + _scorePacman.at(2) + _scorePacman.at(3) + _scorePacman.at(4);
    _totalScore += _scoreNibbler.at(0) + _scoreNibbler.at(1) + _scoreNibbler.at(2) + _scoreNibbler.at(3) + _scoreNibbler.at(4);
}

int Player::getTotalScore(void)
{
    return (_totalScore);    
}

std::vector<int> Player::getScoreNibbler(void)
{
    return (_scoreNibbler);
}

std::vector<int> Player::getScorePacman(void)
{
    return (_scorePacman);
}