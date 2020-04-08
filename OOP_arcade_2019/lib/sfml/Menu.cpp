/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** MenuSfml.cpp
*/

#include "MenuSfml.hpp"
#include "StatsSfml.hpp"

MenuSfml::~MenuSfml()
{

}

MenuSfml::MenuSfml()
{
    _cursorPos = CURSOR_GAME1;
    _maxColor = 0;
}

void MenuSfml::initMenuGraphics(SFML &sf)
{
    _color = sf.generateColor();

    _textBaaah = sf.generateText("BAAAH", 50, 50);
    _textGaming = sf.generateText("Gaming", 30, 100);

    _textPacman = sf.generateText("Pacman", 30, (HEIGHT / 2 - 135));
    _textNibbler = sf.generateText("Nibbler", 30, (HEIGHT / 2 - 10));
    _textStats = sf.generateText("Statistics", 30, (HEIGHT / 2 + 115));
    _textExit = sf.generateText("Exit", 30, (HEIGHT / 2 + 365));

    _textScoreLabel = sf.generateText("Score:", 30, 0);
    _textScore = sf.generateText(std::to_string(sf._player._totalScore), 30, 0);
    _textScoreLabel.setPosition(sf::Vector2f(WIDTH / 10.0f, HEIGHT / 30.0f));
    _textScore.setPosition(sf::Vector2f(WIDTH / 10.0f, HEIGHT / 30.0f + 75));

    _textCursor = sf.generateText(">", 30, (HEIGHT / 2 - 95));
    _textCursor.setPosition(sf::Vector2f(WIDTH / 3.5f, HEIGHT / 2 - 95));

    MenuSfml::moveCursorMenu(sf);
}

void MenuSfml::changePacmanColor(SFML &sf)
{
    if (_cursorPos == CURSOR_GAME1) {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5 + 16), (HEIGHT / 2 - 150), (WIDTH - (WIDTH / 1.25)) - 32, sf::Color::White);
        _textPacman.setFillColor(sf::Color::White);
    } else {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5 + 16), (HEIGHT / 2 - 150), (WIDTH - (WIDTH / 1.25)) - 32, _color);
        _textPacman.setFillColor(_color);
    }
}

void MenuSfml::changeNibblerColor(SFML &sf)
{
    if (_cursorPos == CURSOR_GAME2) {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5) - 75, (HEIGHT / 2) - 25, (WIDTH - (WIDTH / 1.25) + 150), sf::Color::White);
        _textNibbler.setFillColor(sf::Color::White);
    } else {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5) - 75, (HEIGHT / 2) - 25, (WIDTH - (WIDTH / 1.25) + 150), _color);
        _textNibbler.setFillColor(_color);
    }
}

void MenuSfml::changeStatsColor(SFML &sf)
{
    if (_cursorPos == CURSOR_STATS) {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5) - 100, (HEIGHT / 2) + 100, (WIDTH - (WIDTH / 1.25) + 200), sf::Color::White);
        _textStats.setFillColor(sf::Color::White);
    } else {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5) - 100, (HEIGHT / 2) + 100, (WIDTH - (WIDTH / 1.25) + 200), _color);
        _textStats.setFillColor(_color);
    }
}

void MenuSfml::changeExitColor(SFML &sf)
{
    if (_cursorPos == CURSOR_EXIT) {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5 + 85), (HEIGHT / 2) + 350, (WIDTH - (WIDTH / 1.25)) - 170, sf::Color::White);
        _textExit.setFillColor(sf::Color::White);
    } else {
        Geometric::drawUnderline(sf._frame, (WIDTH / 2.5 + 85), (HEIGHT / 2) + 350, (WIDTH - (WIDTH / 1.25)) - 170, _color);
        _textExit.setFillColor(_color);
    }
}

void MenuSfml::moveCursorMenu(SFML &sf)
{
    sf._window.clear();
    if (_cursorPos == CURSOR_GAME1)
        _textCursor.setPosition(sf::Vector2f(WIDTH/3.5f, HEIGHT / 2 - 95));
    if (_cursorPos == CURSOR_GAME2)
        _textCursor.setPosition(sf::Vector2f(WIDTH/3.5f, HEIGHT / 2 + 30));
    if (_cursorPos == CURSOR_STATS)
        _textCursor.setPosition(sf::Vector2f(WIDTH/3.5f, HEIGHT / 2 + 155));
    if (_cursorPos == CURSOR_EXIT)
        _textCursor.setPosition(sf::Vector2f(WIDTH/3.5f, HEIGHT / 2 + 405));
}

int MenuSfml::handleEventMenu(sf::Event const &event, SFML &sf)
{
    if (event.type == sf::Event::Closed) {
        sf._window.close();
        return (CLOSE_WINDOW);
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::F9) {
            return (CLOSE_WINDOW);
        } else if (event.key.code == sf::Keyboard::Up) {
            _cursorPos -= 1;
            if (_cursorPos < CURSOR_GAME1)
                _cursorPos = CURSOR_EXIT;
            MenuSfml::moveCursorMenu(sf);
        } else if (event.key.code == sf::Keyboard::Down) {
            _cursorPos += 1;
            if (_cursorPos > CURSOR_EXIT)
                _cursorPos = CURSOR_GAME1;
            MenuSfml::moveCursorMenu(sf);
        } else if (event.key.code == sf::Keyboard::Enter) {
            return (OPT_SELECTED);
        } else if (event.key.code == sf::Keyboard::F) {
            return (PREVIOUS_LIB);
        } else if (event.key.code == sf::Keyboard::G) {
            return (NEXT_LIB);
        }
    }
    return (0);
}

int MenuSfml::printMenuSFML(SFML &sf, Player &pl)
{
    sf::Clock clock;
    sf::Time elapsed;
    sf::Event event;
    StatsSFML ssf;
    int ret_event;
    sf._window.clear();
    sf._textScore.setString(std::to_string(sf._player._totalScore));
    sf.clearFramebuffer(sf._frame);

    MenuSfml::initMenuGraphics(sf);
    while (sf._window.isOpen())
    {
        while (sf._window.pollEvent(event)) {
            ret_event = MenuSfml::handleEventMenu(event, sf);
            if (ret_event == OPT_SELECTED) {
                if (_cursorPos == CURSOR_GAME1)
                    return (MENU_PLAY_PACMAN);
                else if (_cursorPos == CURSOR_GAME2)
                    return (MENU_PLAY_NIBBLER);
                else if (_cursorPos == CURSOR_STATS)
                    ssf.printStatsSFML(sf, sf._player._scoreNibbler, sf._player._scorePacman);
                else if (_cursorPos == CURSOR_EXIT) {
                    sf._window.close();
                    return (MENU_CLOSE_WINDOW);
                }
            } else if (ret_event == NEXT_LIB)
                return (NEXT_LIB);
            else if (ret_event == PREVIOUS_LIB)
                return (PREVIOUS_LIB);
            else if (ret_event == CLOSE_WINDOW)
                return (MENU_CLOSE_WINDOW);
        }
        _textBaaah.setFillColor(_color);
        _textScoreLabel.setFillColor(_color);

        elapsed = clock.getElapsedTime();
        if ((int)(elapsed.asSeconds()) % 2 == 0)
            MenuSfml::modifyColor();

        Geometric::drawBoxParam(sf._frame, (WIDTH / 3), 25, (WIDTH / 3), 175, sf::Color::White);

        MenuSfml::changePacmanColor(sf);
        MenuSfml::changeNibblerColor(sf);
        MenuSfml::changeStatsColor(sf);
        MenuSfml::changeExitColor(sf);

        sf._texture.update(sf._frame->pixels, sf._frame->width, sf._frame->height, 0, 0);
        sf._window.draw(sf._sprite);
        sf._window.draw(_textBaaah);
        sf._window.draw(_textGaming);
        sf._window.draw(_textPacman);
        sf._window.draw(_textNibbler);
        sf._window.draw(_textStats);
        sf._window.draw(_textExit);
        sf._window.draw(_textScoreLabel);
        sf._window.draw(_textScore);
        sf._window.draw(_textCursor);
        sf._window.display();
    }
    return (MENU_CLOSE_WINDOW);
}

void MenuSfml::modifyColor(void)
{
    if (_color.r >= 255)
        _maxColor = 1;
    if (_color.r <= 0)
        _maxColor = 0;
    if (_maxColor == 1)
        _color.r--;
    if (_maxColor == 0)
        _color.r++;
}
