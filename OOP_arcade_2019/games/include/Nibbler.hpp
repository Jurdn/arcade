/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Nibbler.hpp
*/

#ifndef __NIBBLER__HPP__
#define __NIBBLER__HPP__

#define EMPTY ' '
#define OBSTACLE '#'
#define FRUIT 'x'
#define SNAKE 'o'
#define HEAD 'O'
#define BORDER '#'
#define UP 42
#define LEFT 43
#define DOWN 44
#define RIGHT 45
#define NB_FRUITS 13
#define SCORE_FRUITS 50
#define SCORE_WIN 500

#include "IGames.hpp"
#include <algorithm>

class Nibbler : public IGames {
    public:
        Nibbler();
        virtual ~Nibbler();

        virtual std::vector<std::string> const &getMap();

        virtual bool processInput(int key);
        virtual bool checkEnd();
        virtual void initGame();
        virtual std::string const getName();
        virtual int getScore();
        virtual void restart();
        void createMap();
        void generateFruits();
        int getFruitsLeft() const;

        /*Movement functions*/
        int checkDirection();
        void moveSnake(int x, int y);
        bool checkMovement(int new_tile, int y, int x);
        void updateMap();

        void addSnakeLength();
        void deleteFruitFromList(int y, int x);
        void newIteration();

        int _direction;
        std::vector<std::string> _map;
        std::vector<std::pair<int, int>> _coordinates;
        std::vector<std::pair<int, int>> _fruits;
        int _score;
    protected:
    private:
};

#endif
