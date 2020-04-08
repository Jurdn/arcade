/*
** EPITECH PROJECT, 2020
** Nibbler.cpp
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

std::vector<std::string> temp = {"####################",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#      oooO        #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "####################"};


Nibbler::Nibbler()
{

}

Nibbler::~Nibbler()
{
}

void Nibbler::restart()
{
    _map = temp;
    _coordinates.clear();
    _fruits.clear();
    initGame();
}

void Nibbler::generateFruits()
{
    int rand_x = 0;
    int rand_y = 0;
    rand_x = rand() % 18;
    rand_y = rand() % 18;
    if (_map[rand_y][rand_x] == EMPTY) {
        _fruits.push_back(std::make_pair(rand_y, rand_x));
        _map[rand_y][rand_x] = FRUIT;
    }
    if (_fruits.size() >= (NB_FRUITS - 1))
        return;
    else
        generateFruits();
}

void Nibbler::initGame()
{
    /*int temp[19][19] =  {{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 5},
                        {5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5},
                        {5, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 5},
                        {5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5},
                        {5, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 5},
                        {5, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 5},
                        {5, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 5},
                        {5, 0, 0, 0, 0, 0, 1, 3, 3, 3, 4, 0, 1, 0, 0, 0, 0, 0, 5},
                        {5, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 5},
                        {5, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 5},
                        {5, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 5},
                        {5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5},
                        {5, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 5},
                        {5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5},
                        {5, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 5},
                        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}};*/
    /*int temp[19][19] =  {{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}};*/
    _coordinates.push_back(std::make_pair(9, 10));
    _coordinates.push_back(std::make_pair(9, 9));
    _coordinates.push_back(std::make_pair(9, 8));
    _coordinates.push_back(std::make_pair(9, 7));
    _direction = RIGHT;
    _score = 0;
    _map = temp;
    srand(time(NULL));
    generateFruits();
}

void Nibbler::updateMap()
{
    for (int i = 0; i != 19; i++) {
        for (int j = 0; j != 19; j++) {
            if (_map[i][j] == SNAKE || _map[i][j] == HEAD)
                _map[i][j] = EMPTY;
        }
    }
    _map[_coordinates[0].first][_coordinates[0].second] = HEAD;
    for (int i = 1; i < _coordinates.size(); i++)
        _map[_coordinates[i].first][_coordinates[i].second] = SNAKE;
}

void Nibbler::moveSnake(int x, int y)
{
    std::pair<int, int> old_pos;
    std::pair<int, int> temp;
    old_pos = _coordinates[0];
    _coordinates[0] = std::make_pair(_coordinates[0].first + y, _coordinates[0].second + x);
    for (int i = 1; i < _coordinates.size(); i++) {
        temp = _coordinates[i];
        _coordinates[i] = old_pos;
        old_pos = temp;
    }
    _map[old_pos.first][old_pos.second] = ' ';
}

void Nibbler::addSnakeLength()
{
    std::pair<int, int> tail = _coordinates.back();
    std::pair<int, int> new_cell = std::make_pair(0, 0);
    if (_map[tail.first + 1][tail.second] == EMPTY)
        new_cell = std::make_pair(tail.first + 1, tail.second);
    else if (_map[tail.first - 1][tail.second] == EMPTY)
        new_cell = std::make_pair(tail.first - 1, tail.second);
    else if (_map[tail.first][tail.second + 1] == EMPTY)
        new_cell = std::make_pair(tail.first, tail.second + 1);
    else if (_map[tail.first][tail.second - 1] == EMPTY)
        new_cell = std::make_pair(tail.first, tail.second - 1);
    if (new_cell.first == 0 && new_cell.second == 0)
        return; //endgame;
    _coordinates.push_back(new_cell);
    _score += SCORE_FRUITS;
    return;
}

void Nibbler::deleteFruitFromList(int y, int x)
{
    _fruits.erase(std::find(_fruits.begin(), _fruits.end(), std::make_pair(y, x)));
}

bool Nibbler::checkMovement(int new_tile, int y, int x)
{
    switch (new_tile) {
        case FRUIT:
            addSnakeLength();
            deleteFruitFromList(y, x);
            moveSnake(x, y);
            break;
        case SNAKE:
        case BORDER:
            return false;
/*        case OBSTACLE:
            //manageCollision();
            break;*/
        case EMPTY:
            moveSnake(x, y);
            break;
        default:
            return true;
    }
    updateMap();
    return true;
}

int Nibbler::checkDirection()
{
    switch (_direction) {
        case UP:
            return checkMovement(_map[_coordinates[0].first - 1][_coordinates[0].second], -1, 0);
        case DOWN:
            return checkMovement(_map[_coordinates[0].first + 1][_coordinates[0].second], 1, 0);
        case LEFT:
            return checkMovement(_map[_coordinates[0].first][_coordinates[0].second - 1], 0, -1);
        case RIGHT:
            return checkMovement(_map[_coordinates[0].first][_coordinates[0].second + 1], 0, 1);
    }
    return 0;
}

bool Nibbler::processInput(int input)
{
        if (input == 'd') {
            _direction -= 1;
            if (_direction < 42)
                _direction = RIGHT;
        }
        else if (input == 'q') {
            _direction += 1;
            if (_direction > 45)
                _direction = UP;
        }
        return (checkDirection());
}

bool Nibbler::checkEnd()
{
    if (_fruits.size() > 0) {
        return true;
    }
    _score += SCORE_WIN;
    return false;
}

std::vector<std::string> const &Nibbler::getMap()
{
    return _map;
}

std::string const Nibbler::getName()
{
    return ("nibbler");
}

int Nibbler::getScore()
{
    return _score;
}