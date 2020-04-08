/*
** EPITECH PROJECT, 2020
** Core.cpp
** File description:
** Core
*/

#include "Core.hpp"

Arcade::Core::Core(IGraphics *graphics)
{
    _graphicLib = graphics;
    _gameLib;
}

Arcade::Core::~Core()
{

}

int Arcade::Core::exitCore()
{
    _graphicLib->exitGraphics();
    return 0;
}

int Arcade::Core::changeGame(int game)
{
    LibManager libManager;

    if (game == MENU_PLAY_PACMAN)
        _gameLib = libManager.getGameLib(PACMAN_PATH);
    if (game == MENU_PLAY_NIBBLER)
        _gameLib = libManager.getGameLib(NIBBLER_PATH);
    _gameLib->initGame();
    dlclose(libManager.getFile());
    return (gameLoop());
}

void Arcade::Core::nextGame(void)
{
    if (_gameLib->getName().compare("nibbler") == 0)
        changeGame(MENU_PLAY_PACMAN);
    else
        changeGame(MENU_PLAY_NIBBLER);
}

void Arcade::Core::previousGraphics(Player &pl)
{
    LibManager libManager;
    std::string graphics_path;

    _graphicLib->exitGraphics();
    if (_graphicLib->getLibName() == "sfml")
        _graphicLib = libManager.getGraphicLib(NCURSES_PATH);
    else if (_graphicLib->getLibName() == "ncurses")
        _graphicLib = libManager.getGraphicLib(LIBCACA_PATH);
    else if (_graphicLib->getLibName() == "libcaca")
        _graphicLib = libManager.getGraphicLib(SFML_PATH);
    _graphicLib->initGraphic(pl);
    dlclose(libManager.getFile());
}

void Arcade::Core::nextGraphics(Player &pl)
{
    LibManager libManager;
    std::string graphics_path;

    _graphicLib->exitGraphics();
    if (_graphicLib->getLibName() == "sfml")
        _graphicLib = libManager.getGraphicLib(LIBCACA_PATH);
    else if (_graphicLib->getLibName() == "ncurses")
        _graphicLib = libManager.getGraphicLib(SFML_PATH);
    else if (_graphicLib->getLibName() == "libcaca")
        _graphicLib = libManager.getGraphicLib(NCURSES_PATH);
    _graphicLib->initGraphic(pl);
}

int Arcade::Core::gameLoop()
{
    int ret_pause;
    int input;

    while (_gameLib->checkEnd() == true) {
        _graphicLib->showGame(_gameLib->getMap(), _gameLib->getScore(), _gameLib->getName());
        input = _graphicLib->getInput();
        if (input == 'p') {
            ret_pause = _graphicLib->showPause();
            if (ret_pause == PAUSE_EXIT) {
                _player->saveFile();
                return (-1);
            } else if (ret_pause == PAUSE_MENU)
                return (0);
        } else if (input == RESTART_GAME) {
            _gameLib->restart();
        } else if (input == NEXT_LIB) {
            nextGraphics(*_player);
        } else if (input == PREVIOUS_LIB) {
            previousGraphics(*_player);
        } else if (input == BACK_MENU_GAME) {
            return (0);
        } else if (input == OTHER_GAME) {
            nextGame();
            return (0);
        } else if (input == EXIT_GAME) {
            _player->saveFile();
            return (-1);
        } else {
            if (_gameLib->processInput(input) == false) {
                _graphicLib->showLose(_gameLib->getScore());
                _player->addScore(_gameLib->getScore(), _gameLib->getName());
                return (0);
            }
        }
    }
    _graphicLib->showWin(_gameLib->getScore());
    _player->addScore(_gameLib->getScore(), _gameLib->getName());
    return (0);
}

int Arcade::Core::coreLoop(std::string const &playerName)
{
    int menuRet = 0;

    _player = new Player(playerName);
    _player->loadPlayer();

    _graphicLib->initGraphic(*_player);

    while (1) {
        menuRet = _graphicLib->showMenu(*_player);
        if (menuRet == MENU_CLOSE_WINDOW) {
            _player->saveFile();
            return (exitCore());
        } else if (menuRet == MENU_PLAY_NIBBLER || menuRet == MENU_PLAY_PACMAN) {
            if (changeGame(menuRet) == -1)
                return (exitCore());
        } else if (menuRet == PREVIOUS_LIB) {
            previousGraphics(*_player);
        } else if (menuRet == NEXT_LIB) {
            nextGraphics(*_player);
        }
    }
    return 0;
}