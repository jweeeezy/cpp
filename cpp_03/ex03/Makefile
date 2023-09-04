#/ -------------------------------------------------------------------------- //

NAME      = nowitsweird
SRC_FILES = main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
CC        = c++
DEBUG_FLAG= $(shell echo $$DEBUG_FLAG)
CSTD      = -std=c++98
CFLAGS    = -Wall -Wextra -Werror -Wshadow -Wno-shadow $(CSTD) $(DEBUG_FLAG)

.PHONY:     all clean fclean re

all:        $(NAME)
$(NAME):    $(OBJ_FILES)
				$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
%.o:        %.cpp
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				rm -rf $(OBJ_FILES)
fclean:     clean
				rm -rf $(NAME)
re:         fclean
				$(MAKE)

#/ -------------------------------------------------------------------------- //
