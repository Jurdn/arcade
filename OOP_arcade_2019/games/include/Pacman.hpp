/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Pacman.hpp
*/

#ifndef __PACMAN__HPP__
#define __PACMAN__HPP__

#define SCORE_GUM 10
#define SCORE_GHOST 100
#define MAP_BORDER '|'
#define MAP_OBSTACLE '='
#define MAP_GUM '.'
#define MAP_EMPTY ' '
#define MAP_PACMAN_WEST 'W'
#define MAP_PACMAN_SOUTH 'S'
#define MAP_PACMAN_EAST 'E'
#define MAP_PACMAN_NORTH 'N'
#define MAP_GHOST 'B'
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define SECONDS_OPEN_CAGE 10

#include "IGames.hpp"
#include <chrono>
#include <algorithm>
#include <ratio>
#include <ctime>


class Pacman : public IGames {
    typedef struct s_ghost {
        int direction;
        std::pair<int, int> pos;
        char map_char;
    } t_ghost;

    public:
        Pacman();
        ~Pacman();

        void initGame(void);

        virtual bool processInput(int);
        virtual bool checkEnd(void);
        virtual std::string const getName();
        virtual std::vector<std::string> const &getMap(void);
        virtual int getScore();
        virtual void restart();

        void makeGumsList();
        bool checkNewTile(std::pair<int, int> new_tile);
        void newIteration(std::pair<int, int>);
        bool checkTimer();
        bool updatePacmanPos(std::pair <int, int>);
        void updateGhostPos();
        void openNicolasCage();
        int changeDirection(t_ghost *ghost);
        void isTileIntersection(t_ghost *ghost);
        void moveGhost(t_ghost *ghost);
        void eatGum(std::pair<int, int> new_tile);
        std::pair<int, int> manageBorder(std::pair<int, int> new_tile);
        std::pair<int, int> getNewTile(int direction, std::pair<int, int> pos);
        void refreshMap();

        std::vector<std::string> _map;
    private:
        int _score;
        int _direction;
        int _gumsCount;
        std::pair<int, int> _p_pos;
        std::vector<t_ghost> _ghosts;
        std::vector<std::pair<int, int>> _g_pos;
        std::chrono::steady_clock::time_point _start_time;
        bool _freeGhosts;
};

#endif
