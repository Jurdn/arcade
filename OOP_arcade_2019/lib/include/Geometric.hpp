/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** Geometric.hpp
*/

#ifndef __GEOMETRIC__HPP__
#define __GEOMETRIC__HPP__

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>

#include "Values.hpp"

struct framebuffer;

class Geometric {
public:
    static void drawPixel(framebuffer *fb, unsigned int x, unsigned int y, sf::Color const &color);
    static void drawBackground(framebuffer *fb, sf::Color const &color);
    static void drawHorizontal(framebuffer *fb, unsigned int y, sf::Color const &color);
    static void drawVertical(framebuffer *fb, unsigned int x, sf::Color const &color);
    static void drawBorder(framebuffer *fb, sf::Color const &color);
    static void drawUnderline(framebuffer *fb,  unsigned int x, unsigned int y, unsigned int width, sf::Color const &color);
    static void drawBoxParam(framebuffer *fb, unsigned int x, unsigned int y, unsigned int width, unsigned int height, sf::Color const &color);
    static void drawBox(framebuffer *fb, unsigned int x, unsigned int y, sf::Color const &color);
    static void drawAnalytics(unsigned int x, unsigned int y, sf::Color const &color, std::vector<int> const &t, sf::RenderWindow &window);
    static void drawBar(framebuffer *fb, unsigned int x, unsigned int y, unsigned int height, sf::Color const &color);
};

#endif