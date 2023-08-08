# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwillert <jwillert@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:46:11 by jwillert          #+#    #+#              #
#    Updated: 2023/08/07 18:50:17 by jwillert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
SRC_FILES	= megaphone.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)
CC			= c++
CFLAGS		= -std=c++98 -Wall -Wextra -Werror

.PHONY:		all clean fclean re

all:		$(NAME)
$(NAME): 	$(OBJ_FILES)
				$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
%.o:		%.cpp
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				rm -rf $(OBJ_FILES)
fclean:		clean
				rm -rf $(NAME)
re:			fclean
				$(MAKE)