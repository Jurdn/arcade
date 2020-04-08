/*
** EPITECH PROJECT, 2020
** ARCADE
** File description:
** ncurses.cpp
*/

#ifndef __VALUES__HPP__
#define __VALUES__HPP__

#define WIDTH 1920
#define HEIGHT 1080

#define CURSOR_GAME1 0
#define CURSOR_GAME2 1
#define CURSOR_STATS 2
#define CURSOR_EXIT 3

#define CURSOR_PAUSE_RESUME 4
#define CURSOR_PAUSE_MENU 5
#define CURSOR_PAUSE_EXIT 6

#define MY_KEY_UP 555
#define MY_KEY_DOWN 556
#define MY_KEY_LEFT 557
#define MY_KEY_RIGHT 558

#define CLOSE_WINDOW 69
#define OPT_SELECTED 70
#define CHANGE_LIB 71

#define OTHER_GAME 9999
#define RESTART_GAME 9998
#define BACK_MENU_GAME 9997
#define EXIT_GAME 9996

#define MENU_PLAY_NIBBLER 199
#define MENU_PLAY_PACMAN 200
#define NEXT_LIB 201
#define PREVIOUS_LIB 202
#define MENU_NEXT_GAME 203
#define MENU_PREVIOUS_GAME 204
#define MENU_STATS 205
#define MENU_CLOSE_WINDOW 206

#define PAUSE_RESUME 600
#define PAUSE_MENU 601
#define PAUSE_EXIT 602

#define PAUSE 72

#define EXIT_ERROR 84
#define EXIT_OK 0

#define KEY_NONE 999
#define KEY_WEST 998
#define KEY_EAST 997
#define KEY_SOUTH 996
#define KEY_NORTH 995

#define GAME_KEY_PRESSED 1000

#define CACA_WIDTH 250
#define CACA_HEIGHT 40

#define FONT_PATH "./assets/fonts/arcade_n.ttf"

#define NIBBLER_PATH "./games/lib_arcade_nibbler.so"
#define PACMAN_PATH "./games/lib_arcade_pacman.so"

#define SFML_PATH "./lib/lib_arcade_sfml.so"
#define NCURSES_PATH "./lib/lib_arcade_ncurses.so"
#define LIBCACA_PATH "./lib/lib_arcade_libcaca.so"

#define ARCADE_TEXTURE_PATH "./assets/spriteSheetArcade.png"

#define HELP_MSG "USAGE:\n\t./arcade [lib]"

#endif