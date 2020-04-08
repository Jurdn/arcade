#include "Sfml.hpp"

SFML::GameSfml::~GameSfml() 
{

}

SFML::GameSfml::GameSfml() 
{

}

void SFML::GameSfml::initGameSfml(SFML &sf) 
{
    _clock.restart();
    _arcadeTexture.loadFromFile(ARCADE_TEXTURE_PATH);

    _textScoreLabel = sf.generateText("Score:", 30, 0);
    _textScore = sf.generateText(std::to_string(0), 30, 0);
    _textScoreLabel.setPosition(sf::Vector2f(WIDTH / 10.0f, HEIGHT / 30.0f));
    _textScore.setPosition(sf::Vector2f(WIDTH / 25.0f, HEIGHT / 30.0f + 75));

    _spriteWall.setTexture(_arcadeTexture);
    _spriteWall.setPosition(sf::Vector2f(WIDTH / 3.0f, HEIGHT / 30.0f));
    _spriteWall.setTextureRect({32 * 5, 0, 32, 32});

    _spriteHead.setTexture(_arcadeTexture);
    _spriteHead.setPosition(sf::Vector2f(WIDTH / 3.0f, HEIGHT / 30.0f));
    _spriteHead.setTextureRect({32 * 0, 0, 32, 32});

    _spriteBody.setTexture(_arcadeTexture);
    _spriteBody.setPosition(sf::Vector2f(WIDTH / 3.0f, HEIGHT / 30.0f));
    _spriteBody.setTextureRect({32 * 2, 0, 32, 32});

    _spritePoint.setTexture(_arcadeTexture);
    _spritePoint.setPosition(sf::Vector2f(WIDTH / 3.0f, HEIGHT / 30.0f));
    _spritePoint.setTextureRect({32 * 3, 0, 32, 32});

    _spriteEnnemy.setTexture(_arcadeTexture);
}

void SFML::GameSfml::showGame(SFML &sf, sf::RenderWindow &window, framebuffer *frame, sf::Sprite &sprite, sf::Texture &texture, std::vector<std::string> const &map, int score, std::string const game) 
{
    sf::Time elapsed;
    std::vector<std::string> mapCopy = map;
    int x = WIDTH / 2 - 10 * 32;
    int y = HEIGHT / 2 - 10 * 32;
    int currentX = 0;

    if (game.compare("pacman") == 0)
        _textScoreLabel.setFillColor(sf::Color::Blue);
    else
        _textScoreLabel.setFillColor(sf::Color::Red);
    _textScore.setString(std::to_string(score));
    _clock.restart();
    elapsed = _clock.getElapsedTime();
    sf.clearFramebuffer(frame);
    while (window.isOpen() && (int)(elapsed.asMilliseconds()) < 175) {
        window.clear();
        elapsed = _clock.getElapsedTime();
        if ((int)(elapsed.asMilliseconds()) % 75 == 0) {
            if (game.compare("pacman") == 0)
                _spritePoint.setTextureRect({32 * 2, 64, 32, 32});
            else
                _spritePoint.setTextureRect({32 * 4, 0, 32, 32});
        } else {
            if (game.compare("pacman") == 0)
                _spritePoint.setTextureRect({32 * 1, 64, 32, 32});
            else
                _spritePoint.setTextureRect({32 * 3, 0, 32, 32});
        }
        texture.update(frame->pixels, frame->width, frame->height, 0, 0);
        window.draw(sprite);
        window.draw(_textScoreLabel);
        window.draw(_textScore);
        for (int i = 0; i < map.size(); i++) {
            for (char &c : mapCopy.at(i)) {
                if (c == '#') {
                    _spriteWall.setTextureRect({32 * 5, 0, 32, 32});
                    _spriteWall.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteWall);
                } else if (c == '|' || c == '=') {
                    _spriteWall.setTextureRect({32 * 0, 64, 32, 32});
                    _spriteWall.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteWall);
                } else if (c == 'O') {
                    _spriteHead.setTextureRect({32 * 0, 0, 32, 32});
                    _spriteHead.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteHead);
                } else if (c == 'o') {
                    _spriteBody.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteBody);
                } else if (c == 'x') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spritePoint.setTextureRect({32 * 4, 0, 32, 32});
                    else
                        _spritePoint.setTextureRect({32 * 3, 0, 32, 32});
                    _spritePoint.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spritePoint);
                } else if (c == '.') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spritePoint.setTextureRect({32 * 2, 64, 32, 32});
                    else
                        _spritePoint.setTextureRect({32 * 1, 64, 32, 32});
                    _spritePoint.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spritePoint);
                } else if (c == 'E') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spriteHead.setTextureRect({32 * 0, 32, 32, 32});
                    else
                        _spriteHead.setTextureRect({32 * 1, 32, 32, 32});
                    _spriteHead.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteHead);
                } else if (c == 'N') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spriteHead.setTextureRect({32 * 2, 32, 32, 32});
                    else
                        _spriteHead.setTextureRect({32 * 3, 32, 32, 32});
                    _spriteHead.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteHead);
                } else if (c == 'W') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spriteHead.setTextureRect({32 * 4, 32, 32, 32});
                    else
                        _spriteHead.setTextureRect({32 * 5, 32, 32, 32});
                    _spriteHead.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteHead);
                } else if (c == 'S') {
                    if ((int)(elapsed.asMilliseconds()) % 150 > 75)
                        _spriteHead.setTextureRect({32 * 6, 32, 32, 32});
                    else
                        _spriteHead.setTextureRect({32 * 7, 32, 32, 32});
                    _spriteHead.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteHead);
                } else if (c == 'B') {
                    _spriteEnnemy.setTextureRect({32 * 3, 64, 32, 32});
                    _spriteEnnemy.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteEnnemy);
                } else if (c == 'C') {
                    _spriteEnnemy.setTextureRect({32 * 5, 64, 32, 32});
                    _spriteEnnemy.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteEnnemy);
                } else if (c == 'D') {
                    _spriteEnnemy.setTextureRect({32 * 6, 64, 32, 32});
                    _spriteEnnemy.setPosition(sf::Vector2f(x + (currentX * 32), y + (i * 32)));
                    window.draw(_spriteEnnemy);
                }
                currentX++;
            }
            currentX = 0;
        }
        window.display();
    }

}