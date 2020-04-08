##
## EPITECH PROJECT, 2020
## MAKEFILE
## File description:
## MAKEFILE
##

# PATH
ARCADEPATH		=	main/
LIBPATH			=	lib/
GAMESPATH		=	games/
SRCPATH			=	src/
INTERPATH		=	interface/

SHORTPPATH		=	pacman/
SHORTNPATH		=	nibbler/
LIBSPATH		=	$(LIBPATH)sfml/
LIBNPATH		=	$(LIBPATH)ncurses/
LIBCPATH		=	$(LIBPATH)libcaca/
PLAYERPATH		=	$(LIBPATH)player/

PACMANPATH		=	$(GAMESPATH)pacman/
NIBBLERPATH		=	$(GAMESPATH)nibbler/

# SOURCES
ARCADESRC		=	$(ARCADEPATH)$(SRCPATH)Main.cpp	\
					$(ARCADEPATH)$(SRCPATH)Core.cpp	\
					$(ARCADEPATH)$(SRCPATH)Player.cpp	\
					$(ARCADEPATH)$(SRCPATH)LibManager.cpp	\

NCURSESSRC		=	$(LIBNPATH)Main.cpp	\
					$(LIBNPATH)Ncurses.cpp	\
					$(LIBNPATH)Menu.cpp	\
					$(LIBNPATH)Statistics.cpp	\

SFMLSRC			=	$(LIBSPATH)Main.cpp	\
					$(LIBSPATH)Sfml.cpp	\
					$(LIBSPATH)Geometric.cpp	\
					$(LIBSPATH)Menu.cpp	\
					$(LIBSPATH)Statistics.cpp	\
					$(LIBSPATH)Game.cpp	\

LIBCACASRC		=	$(LIBCPATH)Main.cpp	\
					$(LIBCPATH)Libcaca.cpp	\
					$(LIBCPATH)Statistics.cpp	\

NIBBLERSRC		=	$(NIBBLERPATH)Main.cpp	\
					$(NIBBLERPATH)Nibbler.cpp	\

PACMANSRC		=	$(PACMANPATH)Main.cpp	\
					$(PACMANPATH)Pacman.cpp	\

# OBJS
ARCADEOBJ		=	$(ARCADESRC:.cpp=.o)
NCURSESOBJ		=	$(NCURSESSRC:.cpp=.o)
SFMLOBJ			=	$(SFMLSRC:.cpp=.o)
LIBCACAOBJ		=	$(LIBCACASRC:.cpp=.o)
NIBBLEROBJ		=	$(NIBBLERSRC:.cpp=.o)
PACMANOBJ		=	$(PACMANSRC:.cpp=.o)

# COMPILATION FLAGS
SFML			=	-l sfml-graphics -l sfml-window -l sfml-system
NCURSES			=	-l ncurses
LIBCACA			=	`pkg-config --libs --cflags caca`
DLLIB			=	-ldl
FPICFLAG		=	-fPIC
# CPPFLAGS		+=	-Wall -Werror -Wextra -Wno-deprecated

INTERINCLUDE	=	-I./$(INTERPATH)
ARCADEINCLUDE	=	${INTERINCLUDE} -I./$(ARCADEPATH)include/ -std=c++11 -rdynamic
GAMESINCLUDE	=	${INTERINCLUDE} -I./$(GAMESPATH)include/ -fPIC -std=c++11 -rdynamic
LIBINCLUDE		=	${INTERINCLUDE} -I./$(LIBPATH)include/ -fPIC -std=c++11 -rdynamic

SHARED			=	-shared
GCC				=	g++
RM				=	rm -f
MV				=	mv

# RULES NAMES
ARCADENAME		=	arcade
GAMESNAME		=	games
LIBNAME			=	lib

ARCADERULE		=	arcade_rule
GAMESRULE		=	games_rule
LIBRULE			=	lib_rule
SFMLRULE		=	sfml_rule
LIBCACARULE		=	libcaca_rule
NCURSESRULE		=	ncurses_rule
PACMANRULE		=	pacman_rule
NIBBLERRULE		=	nibbler_rule

# BINARY NAMES
ARCADEBINARY	=	arcade
NIBBLERBINARY	=	lib_arcade_nibbler.so
PACMANBINARY	=	lib_arcade_pacman.so
LIBSFBINARY		=	lib_arcade_sfml.so
LIBNCBINARY		=	lib_arcade_ncurses.so
LIBCCBINARY		=	lib_arcade_libcaca.so
SCORETXT		=	score.txt

all:	core games graphicals

core:	$(ARCADERULE)

games:	$(GAMESRULE)

graphicals:	$(LIBRULE)

$(ARCADERULE):	CPPFLAGS = $(ARCADEINCLUDE)
$(ARCADERULE):	$(ARCADEOBJ)
	$(GCC) -o $(ARCADEBINARY) $(ARCADEINCLUDE) $(ARCADEOBJ) $(DLLIB)

$(GAMESRULE):	$(PACMANRULE) $(NIBBLERRULE)
	$(MV) $(PACMANBINARY) $(GAMESPATH)
	$(MV) $(NIBBLERBINARY) $(GAMESPATH)

$(PACMANRULE):	CPPFLAGS = $(GAMESINCLUDE)
$(PACMANRULE):	$(PACMANOBJ)
	$(GCC) -shared -o $(PACMANBINARY) $(PACMANOBJ)

$(NIBBLERRULE):	CPPFLAGS = $(GAMESINCLUDE)
$(NIBBLERRULE):	$(NIBBLEROBJ)
	$(GCC) -shared -o $(NIBBLERBINARY) $(NIBBLEROBJ)

$(LIBRULE):	$(SFMLRULE) $(NCURSESRULE) $(LIBCACARULE)
	$(MV) $(LIBNCBINARY) $(LIBPATH)
	$(MV) $(LIBSFBINARY) $(LIBPATH)
	$(MV) $(LIBCCBINARY) $(LIBPATH)

$(NCURSESRULE):	CPPFLAGS = $(LIBINCLUDE)
$(NCURSESRULE):	$(NCURSESOBJ)
	$(GCC) -shared -o $(LIBNCBINARY) $(NCURSESOBJ) $(NCURSES)

$(SFMLRULE):	CPPFLAGS = $(LIBINCLUDE)
$(SFMLRULE):	$(SFMLOBJ)
	$(GCC) -shared -o $(LIBSFBINARY) $(SFMLOBJ) $(SFML)

$(LIBCACARULE):	CPPFLAGS = $(LIBINCLUDE)
$(LIBCACARULE):	$(LIBCACAOBJ)
	$(GCC) -shared -o $(LIBCCBINARY) $(LIBCACAOBJ) $(LIBCACA)

clean:
	$(RM) $(ARCADEOBJ)
	$(RM) $(NCURSESOBJ)
	$(RM) $(SFMLOBJ)
	$(RM) $(LIBCACAOBJ)
	$(RM) $(PACMANOBJ)
	$(RM) $(NIBBLEROBJ)

fclean:	clean
	$(RM) $(ARCADEBINARY)
	$(RM) $(LIBPATH)$(LIBNCBINARY)
	$(RM) $(LIBPATH)$(LIBSFBINARY)
	$(RM) $(LIBPATH)$(LIBCCBINARY)
	$(RM) $(GAMESPATH)$(NIBBLERBINARY)
	$(RM) $(GAMESPATH)$(PACMANBINARY)
	$(RM) $(SCORETXT)

re:	fclean all

.PHONY: all clean fclean re
