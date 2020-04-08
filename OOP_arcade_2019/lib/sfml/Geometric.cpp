/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** geometric.cpp
*/

#include "Geometric.hpp"
#include "Sfml.hpp"

void Geometric::drawBackground(framebuffer *fb, sf::Color const &color)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH * 4 - 1; x++) {
            drawPixel(fb, x, y, color);
        }
    }
}

void Geometric::drawBorder(framebuffer *fb, sf::Color const &color)
{
    int x = WIDTH / 60;
    int y = HEIGHT / 50;


    drawHorizontal(fb, HEIGHT / 16, color);
    drawHorizontal(fb, HEIGHT - y, color);
    drawVertical(fb, x, color);
    drawVertical(fb, WIDTH - x, color);
}

void Geometric::drawHorizontal(framebuffer *fb, unsigned int y, sf::Color const &color)
{
    for (int x = 0; x < WIDTH * 4; x++) {
        drawPixel(fb, x, y, color);
    }
}

void Geometric::drawVertical(framebuffer *fb, unsigned int x, sf::Color const &color)
{
    for (int y = 0; y < HEIGHT; y++) {
        drawPixel(fb, x, y, color);
    }
}

void Geometric::drawPixel(framebuffer *fb, unsigned int x, unsigned int y, sf::Color const &color)
{
    if ((x <= WIDTH - 1 && static_cast<int>(x) >= 0) && (y <= HEIGHT - 1 && static_cast<int>(y) >= 0)) {
        fb->pixels[4 * (y * fb->width + x)] = color.r;
        fb->pixels[4 * (y * fb->width + x) + 1] = color.g;
        fb->pixels[4 * (y * fb->width + x) + 2] = color.b;
        fb->pixels[4 * (y * fb->width + x) + 3] = color.a;
    }
}

void Geometric::drawUnderline(framebuffer *fb, unsigned int x, unsigned int y, unsigned int width, sf::Color const &color)
{
    for (unsigned int i = 0; i < width; i++) {
        drawPixel(fb, i + x, 100 + y, color);
        drawPixel(fb, i + x, 100 + y + 1, color);
    }
}

void Geometric::drawBoxParam(framebuffer *fb, unsigned int x, unsigned int y, unsigned int width, unsigned int height, sf::Color const &color)
{
    for (unsigned int i = 0; i < width; i++) {
        drawPixel(fb, i + x, y, color);
        drawPixel(fb, i + x, y + 1, color);
        drawPixel(fb, i + x, height + y, color);
        drawPixel(fb, i + x, height + y + 1, color);
    }

    for (unsigned int j = 0; j < height; j++) {
        drawPixel(fb, x, j + y, color);
        drawPixel(fb, x + 1, j + y, color);
        drawPixel(fb, x + width, j + y, color);
        drawPixel(fb, x + width + 1, j + y, color);
    }
}

void Geometric::drawBox(framebuffer *fb, unsigned int x, unsigned int y, sf::Color const &color)
{
    int x_max = (WIDTH / 2) * 75 / 100;
    int y_max = (HEIGHT / 2) * 75 / 100;

    for (int i = 0; i < x_max; i++) {
        drawPixel(fb, i + x, y, color);
        drawPixel(fb, i + x, y_max + y, color);
    }
    for (int j = 0; j < y_max; j++) {
        drawPixel(fb, x, j + y, color);
        drawPixel(fb, x + x_max, j + y, color);
    }
}

void Geometric::drawAnalytics(unsigned int x, unsigned int y, sf::Color const &color, std::vector<int> const &t, sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(5, t[0]));
    rectangle.setFillColor(color);

    for (int i = 0; i < 100; i++) {
        rectangle.setSize(sf::Vector2f(5, t[i] * 2));
        rectangle.setPosition(sf::Vector2f(x + (i * 7) + 10 - 1, y + 400 - t[i] * 2));
        window.draw(rectangle);
    }
}

void Geometric::drawBar(framebuffer *fb, unsigned int x, unsigned int y, unsigned int height, sf::Color const &color)
{
    for (unsigned int i = 0; i <= height; i++) {
        for (int j = 0; j < 5; j++) {
            drawPixel(fb, j + x, i + y, color);
        }
    }
}