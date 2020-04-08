/*
** EPITECH PROJECT, 2020
** LibManager.cpp
** File description:
** LibManager
*/

#include "LibManager.hpp"

Arcade::LibManager::LibManager()
{
}

Arcade::LibManager::~LibManager()
{
}

void *Arcade::LibManager::openLib(char const *filepath)
{
    // printf("%s\n", filepath);
    void *file = dlopen(filepath, RTLD_LAZY);

    if (!file) {
        std::cerr << "ERROR: Bad library" << std::endl;
        return (NULL);
    }
    //this->_filepath = filepath;
    // std::cerr << "OK" << std::endl;
    return (file);
}

IGames *Arcade::LibManager::getGameLib(char const *filepath)
{
    void *file;
    const char *dlsymError;
    IGames*(*getInterface)();
    if ((file = openLib(filepath)) == NULL)
        return (NULL);
    dlerror();
    // printf("Opened game lib\n");
    getInterface = (IGames *(*)())dlsym(file, "getInterface");
    dlsymError = dlerror();
    if (dlsymError)
        return (NULL);
    _file = file;
    return (getInterface());
}

IGraphics *Arcade::LibManager::getGraphicLib(char const *filepath)
{
    void *file;
    const char *dlsymError;
    IGraphics*(*getInter)();
    if ((file = this->openLib(filepath)) == NULL)
        return (NULL);
    dlerror();
    getInter = (IGraphics *(*)())dlsym(file, "getInterface");
    dlsymError = dlerror();
    if (dlsymError)
        return (NULL);
    _file = file;
    return (getInter());
}

void *Arcade::LibManager::getFile()
{
    return &_file;
}