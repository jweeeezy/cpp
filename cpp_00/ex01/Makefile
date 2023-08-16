NAME		= 	phonebook
LOG_FILE	=	logfile.txt
SRC_FILES	=	main.cpp \
				class.Contact.cpp \
				class.Phonebook.cpp \
				utils.cpp
OBJ_FILES	= 	$(SRC_FILES:.cpp=.o)
CC			= 	c++
DEBUG_FLAG  = 	$(shell echo $$DEBUG_FLAG)
CFLAGS		= 	-std=c++98 -Wall -Wextra -Werror $(DEBUG_FLAG)

.PHONY:		all clean fclean re run

all:		$(NAME)
$(NAME): 	$(OBJ_FILES)
				$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
%.o:		%.cpp
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				rm -rf $(OBJ_FILES)
				rm -rf $(LOG_FILE)
fclean:		clean
				rm -rf $(NAME)
re:			fclean
				$(MAKE)
run:		all
			@./$(NAME) TEST 2>$(LOG_FILE)