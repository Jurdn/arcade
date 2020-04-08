/*
** EPITECH PROJECT, 2020
** LibManager.hpp
** File description:
** LibManager
*/

#ifndef LIBMANAGER_HPP_
#define LIBMANAGER_HPP_

#include "IGraphics.hpp"
#include "IGames.hpp"
#include <dlfcn.h>

namespace Arcade {
    class LibManager {
        public:
            LibManager();
            ~LibManager();
            IGraphics *getGraphicLib(const char *filepath);
            IGames *getGameLib(const char *filepath);
            void *openLib(char const *filepath);
            void *getFile();
        protected:
            void *_file;
        private:
    };
};

#endif /* !LIBMANAGER_HPP_ */
