NAME 		:= so_long
CC 			?= gcc
CFLAGS 		:= -Wall -Wextra -Werror 
TEST_FLAGS 	?= -g -fsanitize=address
LIBFTDIR 	= libft/
LIBFT		= libft/libft.a

OBJ 		:= $(addprefix obj/, so_long.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) all

test: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_FLAGS) $^ -o $@ $(LIBFT)

obj/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf obj/
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f test
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all test clean fclean re