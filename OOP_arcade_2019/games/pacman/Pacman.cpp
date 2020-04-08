/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"
#include <iostream>

std::vector<std::string> temp_map =
{
"|||||||||||||||||||",
"|                 |",
"| ====== = ====== |",
"|        =        |",
"|= === ===== === =|",
"|      =====      |",
"| == =       = == |",
"| == = ===== = == |",
"|    =       =    |",
"|= === ===== === =|",
"|    = =   = =    |",
"| == = =   = = == |",
"|      =====      |",
"| ====   E   ==== |",
"|  =   =====   =  |",
"|= = = ===== = = =|",
"|    =   =   =    |",
"| ====== = ====== |",
"|                 |",
"|||||||||||||||||||"
};

Pacman::Pacman()
{
}

Pacman::~Pacman()
{

}

void Pacman::restart()
{
    _map = temp_map;
    _ghosts.clear();
    _g_pos.clear();
    initGame();
}

void Pacman::makeGumsList()
{
    for (int i = 0; i != _map.size(); i++) {
        for (int j = 0; j != _map[i].length(); j++) {
            if (_map[i][j] == MAP_EMPTY)
                _g_pos.push_back(std::make_pair(i, j));
        }
    }
}

void Pacman::initGame(void)
{
    srand(time(NULL));
    _map = temp_map;
    _p_pos = std::make_pair(13, 9);
    _ghosts.push_back({UP, std::make_pair(11, 8), 'B'});
    _ghosts.push_back({UP, std::make_pair(11, 9), 'C'});
    _ghosts.push_back({UP, std::make_pair(11, 10), 'D'});
    _direction = RIGHT;
    _score = 0;
    makeGumsList();
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(10, 8)));
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(10, 9)));
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(10, 10)));
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(11, 8)));
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(11, 9)));
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), std::make_pair(11, 10)));
    refreshMap();
    _freeGhosts = false;
    _start_time = std::chrono::steady_clock::now();
}

std::string const Pacman::getName()
{
    return ("pacman");
}

bool Pacman::checkEnd(void)
{
    if (_g_pos.size() <= 0)
        return (false);
    return true;
}

std::vector<std::string> const &Pacman::getMap(void)
{
    return (_map);
}

bool Pacman::checkNewTile(std::pair<int, int> new_tile)
{
    if (_map[new_tile.first][new_tile.second] == MAP_OBSTACLE)
        return false;
    return true;
}

void Pacman::refreshMap()
{
    for (int i = 0; i != _map.size(); i++) {
        for (int j = 0; j != _map[i].size(); j++) {
            if (_map[i][j] == MAP_PACMAN_EAST || _map[i][j] == MAP_PACMAN_NORTH ||
                _map[i][j] == MAP_PACMAN_SOUTH ||_map[i][j] == MAP_PACMAN_WEST
                || _map[i][j] == _ghosts[0].map_char ||_map[i][j] == _ghosts[1].map_char ||
                _map[i][j] == _ghosts[2].map_char)
                _map[i][j] = MAP_EMPTY;
        }
    }
    switch (_direction) {
        case UP:
            _map[_p_pos.first][_p_pos.second] = MAP_PACMAN_NORTH;
            break;
        case DOWN:
            _map[_p_pos.first][_p_pos.second] = MAP_PACMAN_SOUTH;
            break;
        case LEFT:
            _map[_p_pos.first][_p_pos.second] = MAP_PACMAN_WEST;
            break;
        case RIGHT:
            _map[_p_pos.first][_p_pos.second] = MAP_PACMAN_EAST;
            break;
    }
    for (int i = 0; i != _g_pos.size(); i++)
        _map[_g_pos[i].first][_g_pos[i].second] = MAP_GUM;
    for (int i = 0; i != _ghosts.size(); i++)
        _map[_ghosts[i].pos.first][_ghosts[i].pos.second] = _ghosts[i].map_char;
}

void Pacman::eatGum(std::pair<int, int> new_tile)
{
    _score += SCORE_GUM;
    _g_pos.erase(std::find(_g_pos.begin(), _g_pos.end(), new_tile));
}

std::pair<int, int> Pacman::manageBorder(std::pair<int, int> new_tile)
{
    if (new_tile.first == 0)
        new_tile.first = 18;
    else if (new_tile.first == 19)
        new_tile.first = 1;
    else if (new_tile.second == 18)
        new_tile.second = 1;
    else if (new_tile.second == 0)
        new_tile.second = 17;
    if (_map[new_tile.first][new_tile.second] == MAP_GUM)
        eatGum(new_tile);
    return new_tile;
}

bool Pacman::updatePacmanPos(std::pair<int, int> new_tile)
{
    switch (_map[new_tile.first][new_tile.second]) {
        case MAP_GUM:
            _p_pos = new_tile;
            eatGum(new_tile);
            return true;
        case MAP_BORDER:
            _p_pos = manageBorder(new_tile);
            return true;
        case MAP_EMPTY:
            _p_pos = new_tile;
            return true;
        case 'B':
        case 'C':
        case 'D':
            return true;
        case MAP_OBSTACLE:
            return false;
    }
    return true;
}

std::pair<int, int> Pacman::getNewTile(int direction, std::pair<int, int> pos)
{
    std::pair<int, int> new_tile;
    if (direction == UP)
        new_tile = std::make_pair(pos.first - 1, pos.second);
    if (direction == DOWN)
        new_tile = std::make_pair(pos.first + 1, pos.second);
    if (direction == LEFT)
        new_tile = std::make_pair(pos.first, pos.second - 1);
    if (direction == RIGHT)
        new_tile = std::make_pair(pos.first, pos.second + 1);
    return new_tile;
}

void Pacman::openNicolasCage()
{
    _map[9][8] = MAP_EMPTY;
    _map[9][9] = MAP_EMPTY;
    _map[9][10] = MAP_EMPTY;
}

bool Pacman::processInput(int input)
{
    int direction_svg = _direction;
    std::pair<int, int> new_tile = getNewTile(direction_svg, _p_pos);
    switch (input) {
        case 'z':
            _direction = UP;
            new_tile = getNewTile(_direction, _p_pos);
            break;
        case 's':
            _direction = DOWN;
            new_tile = getNewTile(_direction, _p_pos);
            break;
        case 'q':
            _direction = LEFT;
            new_tile = getNewTile(_direction, _p_pos);
            break;
        case 'd':
            _direction = RIGHT;
            new_tile = getNewTile(_direction, _p_pos);
            break;
    }
    if (_map[new_tile.first][new_tile.second] == MAP_OBSTACLE) {
        new_tile = getNewTile(direction_svg, _p_pos);
        _direction = direction_svg;
    }
    if (updatePacmanPos(new_tile) == false) {
        _direction = direction_svg;
    }
    if (_freeGhosts == false && checkTimer() == true) {
        _freeGhosts = true;
        openNicolasCage();
    }
    if (_freeGhosts == true)
        updateGhostPos();
    refreshMap();
    for (int i = 0; i != _ghosts.size(); i++) {
        if (_ghosts[i].pos == _p_pos)
            return (false);
    }
    return true;
}

int Pacman::getScore()
{
    return _score;
}

int Pacman::changeDirection(Pacman::t_ghost *ghost)
{
    int opposite_direction = ghost->direction + 2;
    int possible_direction1 = ghost->direction + 1;
    int possible_direction2 = ghost->direction + 3;
    std::pair<int, int> temp_tile;
    if (possible_direction1 > 4)
        possible_direction1 -= 4;
    if (possible_direction2 > 4)
        possible_direction2 -= 4;
    if (checkNewTile(temp_tile = getNewTile(possible_direction1, ghost->pos)) == false &&
        _map[temp_tile.first][temp_tile.second] != 'B' &&
        _map[temp_tile.first][temp_tile.second] != 'C' &&
        _map[temp_tile.first][temp_tile.second] != 'D' &&
        _map[temp_tile.first][temp_tile.second] != MAP_BORDER)
        return possible_direction2;
    else if (checkNewTile(temp_tile = getNewTile(possible_direction2, ghost->pos)) == false &&
        _map[temp_tile.first][temp_tile.second] != 'B' &&
        _map[temp_tile.first][temp_tile.second] != 'C' &&
        _map[temp_tile.first][temp_tile.second] != 'D' &&
        _map[temp_tile.first][temp_tile.second] != MAP_BORDER)
        return possible_direction1;
    else
        return ((rand() % 2) == 0 ? possible_direction1 : possible_direction2);
}

void Pacman::isTileIntersection(Pacman::t_ghost *ghost)
{
    int opposite_direction = ghost->direction + 2;
    int possible_direction1 = ghost->direction + 1;
    int possible_direction2 = ghost->direction + 3;
    std::pair<int, int> temp_tile;
    bool possible = false;
//    std::vector<std::pair<int, int>> tiles;
    if (possible_direction1 > 4)
        possible_direction1 -= 4;
    if (possible_direction2 > 4)
        possible_direction2 -= 4;
    if (checkNewTile(temp_tile = getNewTile(possible_direction1, ghost->pos)) == true &&
        _map[temp_tile.first][temp_tile.second] != 'B' &&
        _map[temp_tile.first][temp_tile.second] != 'C' &&
        _map[temp_tile.first][temp_tile.second] != 'D' &&
        _map[temp_tile.first][temp_tile.second] != MAP_BORDER)
        possible = true;
    if (checkNewTile(temp_tile = getNewTile(possible_direction2, ghost->pos)) == true &&
        _map[temp_tile.first][temp_tile.second] != 'B' &&
        _map[temp_tile.first][temp_tile.second] != 'C' &&
        _map[temp_tile.first][temp_tile.second] != 'D' &&
        _map[temp_tile.first][temp_tile.second] != MAP_BORDER)
        possible = true;
    if (possible == true)
        ghost->direction = ((rand() % 2) == 0) ? ghost->direction : changeDirection(ghost);
}

void Pacman::moveGhost(Pacman::t_ghost *ghost)
{
    int new_direction = ghost->direction;
    std::pair<int, int> new_tile = getNewTile(ghost->direction, ghost->pos);
    if (_map[new_tile.first][new_tile.second] == MAP_OBSTACLE ||
        _map[new_tile.first][new_tile.second] == 'B' ||
        _map[new_tile.first][new_tile.second] == 'C' ||
        _map[new_tile.first][new_tile.second] == 'D' ||
        _map[new_tile.first][new_tile.second] == MAP_BORDER)
        new_direction = changeDirection(ghost);
    if (checkNewTile(new_tile = getNewTile(new_direction, ghost->pos)) == true &&
        _map[new_tile.first][new_tile.second] != 'B' &&
        _map[new_tile.first][new_tile.second] != 'C' &&
        _map[new_tile.first][new_tile.second] != 'D' &&
        _map[new_tile.first][new_tile.second] != MAP_BORDER) {
        ghost->direction = new_direction;
        ghost->pos = new_tile;
    }
}

void Pacman::updateGhostPos()
{
    for (int i = 0; i != _ghosts.size(); i++) {
        isTileIntersection(&_ghosts[i]);
        moveGhost(&_ghosts[i]);
    }
}

bool Pacman::checkTimer()
{
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - _start_time);
    if (diff.count() >= SECONDS_OPEN_CAGE) {
        return true;
    }
    return false;
}