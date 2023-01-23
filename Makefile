NAME 		:= so_long
CC 			?= gcc
CFLAGS 		:= -Wall -Wextra -Werror
CODAMFLAGS  := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
HOMEFLAGS	:= -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/
TEST_FLAGS 	?= #-g -fsanitize=address
LIBFT	 	:= ./libs/libft
LIBMLX		:= ./libs/MLX42
LIBS		:= $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a
HEADERS		:= -I includes/ -I $(LIBFT) -I $(LIBMLX)/include -I $(LIBMLX)/include/MLX42

OBJ 		:= $(addprefix obj/, so_long.o player.o window.o images.o sprites.o map.o bfs.o hook.o actions.o free.o)
TEST_OBJ	:= $(addprefix obj/, test.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(CODAMFLAGS) $^ -o $@

home: $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(HOMEFLAGS) $^ -o $@

$(LIBS): 
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMLX) 

test: $(TEST_OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(CODAMFLAGS) $^ -o $@

obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -c $^ -o $@ $(HEADERS)

clean:
	rm -rf obj/


fclean: clean
	rm -f $(NAME)
	rm -f home
	rm -f test

clean_libs:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all test clean fclean clean_libs re