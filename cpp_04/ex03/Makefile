#/ -------------------------------------------------------------------------- //

NAME      = interfaceandrecap
SRC_FILES = main.cpp \
			AMateria.cpp \
			Ice.cpp \
			Cure.cpp \
			Character.cpp \
			MateriaSource.cpp \
			Floor.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
CC        = c++
DEBUG_FLAG= $(shell echo $$DEBUG_FLAG)
CSTD      = -std=c++98
CFLAGS    = -Wall -Wextra -Werror $(CSTD) $(DEBUG_FLAG)

.PHONY:     all clean fclean re test

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
test:
				export DEBUG_FLAG='-g -DDEBUG=1' && make re && clear
				./$(NAME)

#/ -------------------------------------------------------------------------- //
