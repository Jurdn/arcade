/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"
#include "LibManager.hpp"

int main(int ac, char **av, char **env)
{
    if (ac != 2) {
        std::cout << HELP_MSG << std::endl;
        return (EXIT_ERROR);
    } else {
        if (!av || !env) {
            std::cout << HELP_MSG << std::endl;
            return (EXIT_ERROR);
        }
        if (!av[1]) {
            std::cout << HELP_MSG << std::endl;
            return (EXIT_ERROR);
        }
        std::string name;
        Arcade::LibManager libManager;
        IGraphics *graphics;
        if ((graphics = libManager.getGraphicLib(av[1])) == NULL) {
            printf("selem\n");
            return (84);
        }
        Arcade::Core core(graphics);

        std::cout << "How should I call you ?" << std::endl;
        std::cin >> name;
        for (char &c : name) {
            if (c == '\n' || c == ',' || c == '.') {
                std::cout << "Name should contain invalid character :'(" << std::endl;
                return (EXIT_ERROR);
            }
        }
        if (name.length() > 8)
            name.erase(8);
        (core.coreLoop(name));
        // if (gl.libLoop(av[1], name) == EXIT_ERROR)
        //    return (EXIT_ERROR);
    }
    return (EXIT_OK);
}
