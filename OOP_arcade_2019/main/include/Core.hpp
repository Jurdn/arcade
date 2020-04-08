/*
** EPITECH PROJECT, 2020
** Core.hpp
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "IGames.hpp"
#include "IGraphics.hpp"
#include "LibManager.hpp"
#include <memory>

namespace Arcade {
    class Core {
        public:
            Core(IGraphics *graphics);
            ~Core();
            void init();
            int coreLoop(std::string const &playerName);
            int gameLoop();
            int changeGame(int game);
            void nextGraphics(Player &pl);
            void previousGraphics(Player &pl);
            void nextGame(void);
            int exitCore();
        protected:
        private:
            Player *_player;
            IGames *_gameLib;
            IGraphics *_graphicLib;
    };
};

#endif /* !CORE_HPP_ */
