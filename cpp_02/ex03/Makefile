#/ -------------------------------------------------------------------------- //


# ~~~~~~~>  VARIABLES MAIN PROGRAM


NAME      = bsp
SRC_FILES = main.cpp \
			Fixed.cpp \
			Point.cpp \
			bsp.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
CC        = c++
DEBUG_FLAG= $(shell echo $$DEBUG_FLAG)
CSTD      = -std=c++98

INCLUDES  = -I ./MLX42/include/MLX42/

CFLAGS    = -Wall -Wextra -Werror $(CSTD) $(INCLUDES) $(DEBUG_FLAG)


# ~~~~~~~> VARIABLES MLX42 IMPLEMENTATION


#          ~~~~~~~> dependency: brew

# Installing brew in goinfre:
#'rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew \
	&& git clone --depth=1 \
	https://github.com/Homebrew/brew $HOME/goinfre/.brew && brew update'

BREW_FIND = if test -d /Users/$(USER)/.brew; \
            then echo /Users/$(USER)/.brew/; \
            elif test -d /Users/$(USER)/goinfre/.brew; \
            then echo /Users/$(USER)/goinfre/.brew/; \
            else echo ""; fi
BREW_DIR  = $(shell $(BREW_FIND))

#          ~~~~~~~> dependency: glfw
GLFW_DIR  = $(BREW_DIR)opt/glfw/lib/
GLFW_FIND = if test -d $(GLFW_DIR); \
			then echo "makefile: glfw found"; \
			else echo "makefile: glfw not found" && brew install glfw; \
			fi

#          ~~~~~~~> MLX42
MLX42        = ./MLX42/build/libmlx42.a
MLX42_DIR    = ./MLX42/
MLX42_MAC    = -framework Cocoa -framework OpenGl -framework IOKit
MLX42_CFLAGS = -I include -lglfw -L $(GLFW_DIR) $(MLX42_MAC)


# ~~~~~~~> BUILDING PROCESS


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(MLX42) $(NAME) 
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX42) $(MLX42_CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_FILES)
fclean: clean
	rm -rf $(NAME)
re: fclean
	$(MAKE)

$(MLX42): $(MLX42_DIR)
	cmake ./MLX42/ -B ./MLX42/build
	cmake --build ./MLX42/build -j4
$(MLX42_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git

#/ -------------------------------------------------------------------------- //
