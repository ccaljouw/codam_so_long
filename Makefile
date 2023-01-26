NAME 		:= so_long
CC 			?= gcc
CFLAGS 		:= -Wall -Wextra -Werror
CODAMFLAGS  := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
HOMEFLAGS	:= -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/
LIBFT	 	:= ./libs/libft
LIBMLX		:= ./libs/MLX42
LIBS		:= $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a
HEADERS		:= -I $(LIBFT)  -I $(LIBMLX)/include/MLX42

OBJ 		:= $(addprefix obj/, so_long.o player.o window.o images.o sprites.o init_map.o check_map.o breadth_first_search.o hook.o actions.o free.o utils.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(CODAMFLAGS) $^ -o $@

home: $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(HOMEFLAGS) $^ -o $@

$(LIBS): 
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMLX)

obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@ $(HEADERS)

clean:
	rm -rf obj/
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f home
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all clean fclean re