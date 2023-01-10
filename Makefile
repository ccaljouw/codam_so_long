NAME 		:= so_long
CC 			?= gcc
CFLAGS 		:= -Wall -Wextra -Werror 
TEST_FLAGS 	?= -g -fsanitize=address
LIBFT	 	:= ./libft
LIBMLX		:= ./MLX42
LIBS		:= $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a
HEADERS		:= -I $(LIBFT) -I $(LIBMLX)/include

OBJ 		:= $(addprefix obj/, so_long.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBS): 
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMLX) 

test: $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(TEST_FLAGS) $^ -o $@

obj/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@ $(HEADERS)

clean:
	rm -rf obj/
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f test
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all test clean fclean re