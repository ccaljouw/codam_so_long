CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -rcs
OBJ = $(addprefix $(OBJDIR),ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_tolower.o ft_toupper.o ft_strlen.o ft_strlcpy.o  \
	   ft_strlcat.o ft_strncmp.o ft_strchr.o ft_strrchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_memchr.o ft_bzero.o \
	   ft_atoi.o ft_strnstr.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
	   ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o)
OBJ_BONUS = $(addprefix $(OBJDIR),ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
			ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o get_next_line.o ft_strjoin_free_s1.o)
OBJ_PRINTF = $(addprefix $(OBJDIR), ft_printf/ft_printf.o  ft_printf/ft_printf_set.o ft_printf/ft_printf_getargs.o ft_printf/ft_itoa_printf.o)

OBJDIR = obj/
NAME = libft.a

OBJALL = $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)

all: $(NAME)

bonus:
	$(MAKE) $(NAME) 

$(NAME): $(OBJALL)
	ar $(LIBFLAGS) $(NAME) $(OBJALL)

$(OBJDIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus fclean clean re