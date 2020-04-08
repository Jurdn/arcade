/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Sfml.hpp
*/

#ifndef __SFML__HPP__
#define __SFML__HPP__

#include "Geometric.hpp"
#include "IGraphics.hpp"
// #include "GameSfml.hpp"

struct framebuffer
{
    sf::Uint8 *pixels;
    unsigned int width;
    unsigned int height;
};

class SFML : public IGraphics {
public:
    SFML();
    ~SFML();

    void initGraphic(Player &);
    void showGame(std::vector<std::string> const &map, int score, std::string const &);
    int showPause(void);
    int getInput();
    int showMenu(Player &);
    void showWin(int);
    void showLose(int);
    void exitGraphics(void);
    std::string getLibName(void);

    framebuffer *createFramebuffer(unsigned int width, unsigned int height);
    void clearFramebuffer(framebuffer *);

    sf::Text generateText(std::string const &, int, int);
    sf::Color generateColor(void);
    void modifyColor(void);

    void movePauseCursor(int, sf::Text &);

    sf::RenderWindow _window;
    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::Text _textScoreLabel;
    sf::Text _textScore;

    sf::Event _event;

    class GameSfml {
    public:
        GameSfml();
        ~GameSfml();

        void initGameSfml(SFML &);
        void showGame(SFML &, sf::RenderWindow &, framebuffer *, sf::Sprite &, sf::Texture &, std::vector<std::string> const &, int, std::string const);

        sf::Sprite _spriteHead;
        sf::Sprite _spriteBody;

        sf::Sprite _spritePoint;

        sf::Sprite _spriteEnnemy;

        sf::Sprite _spriteWall;

        sf::Text _textScoreLabel;
        sf::Text _textScore;

        sf::Texture _arcadeTexture;

        sf::Clock _clock;
    };

    SFML::GameSfml _gs;

    sf::Font _font;
    framebuffer *_frame;

    Player _player;
};

#endif