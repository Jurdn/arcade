/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** statistics.cpp
*/

#include "StatsSfml.hpp"

StatsSFML::~StatsSFML()
{

}

StatsSFML::StatsSFML()
{
    _maxColor = 0;
}

void StatsSFML::initStatsGraphics(SFML &sf)
{
    _color = sf.generateColor();

    _textStats = sf.generateText("Statistics", 50, 50);
    _textScoreNibbler = sf.generateText("Nibbler", 30, (HEIGHT / 2 - 200));
    _textScorePacman = sf.generateText("Pacman", 30, (HEIGHT / 2 - 200));
    _textScoreNibbler.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 - 200));
    _textScorePacman.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 - 200));
}

int StatsSFML::handleEventStats(sf::Event const &event, SFML &sf)
{
    if (event.type == sf::Event::Closed) {
        sf._window.close();
        return (CLOSE_WINDOW);
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            return (MENU_STATS);
    }
    return (0);
}

int StatsSFML::printStatsSFML(SFML &sf, std::vector<int> &scoreNibbler, std::vector<int> &scorePacman)
{
    sf::Clock clock;
    sf::Time elapsed;
    sf::Event event;
    int ret_event;
    sf._window.clear();
    sf.clearFramebuffer(sf._frame);

    sf::Text playerText = sf.generateText("Player:", 30, 120);
    playerText.setPosition(sf::Vector2f(WIDTH / 4.0f + 250, 200));
    sf::Text playerName = sf.generateText(sf._player._playerName, 30, 120);
    playerName.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f) - 200, 200));

    sf::Text playerScoreLabel = sf.generateText("Total Score:", 30, HEIGHT - 190);
    sf::Text playerScore = sf.generateText(std::to_string(sf._player._totalScore), 30, HEIGHT - 100);

    sf::Text scoreNibbler1 = sf.generateText(std::to_string(scoreNibbler.at(4)), 30, HEIGHT - 190);
    sf::Text scoreNibbler2 = sf.generateText(std::to_string(scoreNibbler.at(3)), 30, HEIGHT - 190);
    sf::Text scoreNibbler3 = sf.generateText(std::to_string(scoreNibbler.at(2)), 30, HEIGHT - 190);
    sf::Text scoreNibbler4 = sf.generateText(std::to_string(scoreNibbler.at(1)), 30, HEIGHT - 190);
    sf::Text scoreNibbler5 = sf.generateText(std::to_string(scoreNibbler.at(0)), 30, HEIGHT - 190);
    scoreNibbler1.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 - 100));
    scoreNibbler2.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 - 25));
    scoreNibbler3.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 + 50));
    scoreNibbler4.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 + 125));
    scoreNibbler5.setPosition(sf::Vector2f(WIDTH / 4.0f, HEIGHT / 2 + 200));

    sf::Text scorePacman1 = sf.generateText(std::to_string(scorePacman.at(4)), 30, HEIGHT - 190);
    sf::Text scorePacman2 = sf.generateText(std::to_string(scorePacman.at(3)), 30, HEIGHT - 190);
    sf::Text scorePacman3 = sf.generateText(std::to_string(scorePacman.at(2)), 30, HEIGHT - 190);
    sf::Text scorePacman4 = sf.generateText(std::to_string(scorePacman.at(1)), 30, HEIGHT - 190);
    sf::Text scorePacman5 = sf.generateText(std::to_string(scorePacman.at(0)), 30, HEIGHT - 190);
    scorePacman1.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 - 100));
    scorePacman2.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 - 25));
    scorePacman3.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 + 50));
    scorePacman4.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 + 125));
    scorePacman5.setPosition(sf::Vector2f(WIDTH - (WIDTH / 4.0f), HEIGHT / 2 + 200));

    StatsSFML::initStatsGraphics(sf);
    while (sf._window.isOpen()) {
        while (sf._window.pollEvent(event)) {
            ret_event = StatsSFML::handleEventStats(event, sf);
            if (ret_event == MENU_STATS)
                return (0);
            else if (ret_event == CLOSE_WINDOW)
                return (MENU_CLOSE_WINDOW);
        }
        _textStats.setFillColor(_color);
        _textScorePacman.setFillColor(_color);
        _textScoreNibbler.setFillColor(_color);
        playerName.setFillColor(_color);
        playerScoreLabel.setFillColor(_color);

        elapsed = clock.getElapsedTime();
        if ((int)(elapsed.asSeconds()) % 2 == 0)
            StatsSFML::modifyColor();

        sf._texture.update(sf._frame->pixels, sf._frame->width, sf._frame->height, 0, 0);
        sf._window.draw(sf._sprite);
        sf._window.draw(_textStats);
        sf._window.draw(_textScorePacman);
        sf._window.draw(_textScoreNibbler);
        sf._window.draw(playerText);
        sf._window.draw(playerName);
        sf._window.draw(playerScore);
        sf._window.draw(playerScoreLabel);
        sf._window.draw(scoreNibbler1);
        sf._window.draw(scoreNibbler2);
        sf._window.draw(scoreNibbler3);
        sf._window.draw(scoreNibbler4);
        sf._window.draw(scoreNibbler5);
        sf._window.draw(scorePacman1);
        sf._window.draw(scorePacman2);
        sf._window.draw(scorePacman3);
        sf._window.draw(scorePacman4);
        sf._window.draw(scorePacman5);
        sf._window.display();
    }
    return (MENU_CLOSE_WINDOW);
}

void StatsSFML::modifyColor(void)
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
