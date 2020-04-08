/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFML.cpp
*/

#include "Sfml.hpp"
#include "MenuSfml.hpp"

SFML::~SFML()
{

}

SFML::SFML()
{

}

void SFML::initGraphic(Player &pl)
{
    _window.create(sf::VideoMode(WIDTH, HEIGHT), "BAAAH Gaming", sf::Style::Fullscreen);
    _texture.create(WIDTH, HEIGHT);
    _sprite.setTexture(_texture);
    _frame = createFramebuffer(WIDTH, HEIGHT);
    _font.loadFromFile(FONT_PATH);
    _window.setMouseCursorVisible(false);

    _textScoreLabel = generateText("Score:", 30, 0);
    _textScore = generateText("0", 30, 0);
    _textScoreLabel.setPosition(sf::Vector2f(WIDTH / 10.0f, HEIGHT / 30.0f));
    _textScore.setPosition(sf::Vector2f(WIDTH / 10.0f, HEIGHT / 30.0f + 75));

    _textScoreLabel.setFillColor(sf::Color::Red);

    _player = pl;

    _gs.initGameSfml(*this);
}

void SFML::showGame(std::vector<std::string> const &map, int score, std::string const &gameName)
{
    _gs.showGame(*this, _window, _frame, _sprite, _texture, map, score, gameName);
}

int SFML::showPause(void)
{
    sf::Text textPause = generateText("Pause", 30, (HEIGHT / 2 - 95));
    sf::Text textResume = generateText("Resume", 30, (HEIGHT / 2 - 95));
    sf::Text textMenu = generateText("Menu", 30, (HEIGHT / 2 - 95));
    sf::Text textExit = generateText("Exit", 30, (HEIGHT / 2 - 95));
    sf::Text textCursor = generateText(">", 30, (HEIGHT / 2 - 95));
    int cursorPos = PAUSE_RESUME;

    sf::Color co = {100, 100, 100, 255};
    textPause.setPosition(sf::Vector2f(960, 290));
    textResume.setPosition(sf::Vector2f(960, 490));
    textMenu.setPosition(sf::Vector2f(960, 640));
    textExit.setPosition(sf::Vector2f(960, 790));
    textCursor.setPosition(sf::Vector2f(710, 490));
    textPause.setFillColor(co);
    textResume.setFillColor(co);
    textMenu.setFillColor(co);
    textExit.setFillColor(co);
    movePauseCursor(cursorPos, textCursor);
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::Up) {
                    cursorPos -= 1;
                    if (cursorPos < PAUSE_RESUME)
                        cursorPos = PAUSE_EXIT;
                    movePauseCursor(cursorPos, textCursor);
                } else if (_event.key.code == sf::Keyboard::Down) {
                    cursorPos += 1;
                    if (cursorPos > PAUSE_EXIT)
                        cursorPos = PAUSE_RESUME;
                    movePauseCursor(cursorPos, textCursor);
                } else if (_event.key.code == sf::Keyboard::Enter)
                    return (cursorPos);
            }
        }

        if (cursorPos == PAUSE_RESUME) {
            textResume.setFillColor(sf::Color::White);
            textMenu.setFillColor(co);
            textExit.setFillColor(co);
        } else if (cursorPos == PAUSE_MENU) {
            textResume.setFillColor(co);
            textMenu.setFillColor(sf::Color::White);
            textExit.setFillColor(co);
        } else if (cursorPos == PAUSE_EXIT) {
            textResume.setFillColor(co);
            textMenu.setFillColor(co);
            textExit.setFillColor(sf::Color::White);
        }

        Geometric::drawBoxParam(_frame, 610, 140, 700, 800, co);
        Geometric::drawUnderline(_frame, 810, 230, 300, co);

        _texture.update(_frame->pixels, _frame->width, _frame->height, 0, 0);
        _window.draw(_sprite);
        _window.draw(textPause);
        _window.draw(textResume);
        _window.draw(textMenu);
        _window.draw(textExit);
        _window.draw(textCursor);
        _window.display();

    }
    return (PAUSE_RESUME);
}

void SFML::showLose(int score)
{
    sf::Text textLose = generateText("LOOSER!", 50, (HEIGHT / 2 - 50));
    sf::Text textScore = generateText(std::to_string(score), 30, (HEIGHT / 2 + 50));

    textLose.setFillColor(sf::Color::Red);
    _window.clear();
    if (_window.isOpen()) {
        _window.draw(textLose);
        _window.draw(textScore);
        _window.display();
        sf::sleep(sf::seconds(3));
    }
}

void SFML::showWin(int score)
{
    sf::Text textWin = generateText("YOU WON!", 50, (HEIGHT / 2 - 50));
    sf::Text textScore = generateText(std::to_string(score), 30, (HEIGHT / 2 + 50));

    textWin.setFillColor(sf::Color::Green);
    _window.clear();
    if (_window.isOpen()) {
        _window.draw(textWin);
        _window.draw(textScore);
        _window.display();
        sf::sleep(sf::seconds(3));
    }
}

int SFML::showMenu(Player &pl)
{
    MenuSfml ms;

    return (ms.printMenuSFML(*this, pl));
}

int SFML::getInput()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                return ('p');
            else if (_event.key.code == sf::Keyboard::Q)
                return ('q');
            else if (_event.key.code == sf::Keyboard::D)
                return ('d');
            else if (_event.key.code == sf::Keyboard::S)
                return ('s');
            else if (_event.key.code == sf::Keyboard::Z)
                return ('z');
            else if (_event.key.code == sf::Keyboard::I || _event.key.code == sf::Keyboard::O)
                return (OTHER_GAME);
            else if (_event.key.code == sf::Keyboard::R)
                return (RESTART_GAME);
            else if (_event.key.code == sf::Keyboard::M)
                return (BACK_MENU_GAME);
            else if (_event.key.code == sf::Keyboard::E)
                return (EXIT_GAME);
            else if (_event.key.code == sf::Keyboard::G)
                return (NEXT_LIB);
            else if (_event.key.code == sf::Keyboard::F)
                return (PREVIOUS_LIB);
        }
    }
    return (0);
}

void SFML::movePauseCursor(int cursorPos, sf::Text &textCursor)
{
    _window.clear();
    if (cursorPos == PAUSE_RESUME)
        textCursor.setPosition(sf::Vector2f(710, 490));
    if (cursorPos == PAUSE_MENU)
        textCursor.setPosition(sf::Vector2f(710, 640));
    if (cursorPos == PAUSE_EXIT)
        textCursor.setPosition(sf::Vector2f(710, 790));

}

void SFML::exitGraphics(void)
{
    _window.close();
}

std::string SFML::getLibName(void)
{
    return ("sfml");
}

framebuffer* SFML::createFramebuffer(unsigned int width, unsigned int height)
{
    framebuffer *frame = new framebuffer;

    frame->width = width;
    frame->height = height;
    frame->pixels = new sf::Uint8[width * height * 4];
    return (frame);
}

void SFML::clearFramebuffer(framebuffer *fb)
{
    Geometric::drawBackground(fb, sf::Color::Black);
}

sf::Text SFML::generateText(std::string const &text, int size, int y)
{
    sf::Text ret(text, _font);
    ret.setCharacterSize(size);
    ret.setFillColor(sf::Color::White);
    ret.setLetterSpacing(5);
    sf::FloatRect textRect = ret.getLocalBounds();
    ret.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    ret.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 30.0f + y));
    return (ret);
}
sf::Color SFML::generateColor(void)
{
    time_t t;
    sf::Color ret;

    srand((unsigned) time(&t));
    ret.r = (rand() % 250) + 1;
    ret.g = (rand() % 250) + 1;
    ret.b = (rand() % 250) + 1;
    ret.a = 255;
    return (ret);
}

void SFML::modifyColor(void)
{

}
