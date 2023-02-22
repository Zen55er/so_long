NAME =			so_long.a
LIB =			so_long.h
LIBFT_DIR =		../libft
LIBFT =			../libft/libft.a
SR =			
SRC_OBJS =		$(SRC:.c=.o)
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g
MLXFLAGS = 		../mlx_linux/libmlx_Linux.a -lX11 -lXext -lm

all:		$(NAME)

$(NAME):	$(SRC_OBJS)
			@$(MAKE) --no_print_directory -C $(LIBFT_DIR)
			@ar -rcs $(NAME) $(SRC_OBJS) $(LIB)
			$(CC) $(FLAGS) main.c -o so-long $(MLXFLAGS) $(NAME) $(LIBFT) -fsanitize=address

clean:
			@rm -f $(SRC_OBJS)
			@$(MAKE) --no_print_directory -C $(LIBFT_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no_print_directory -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY: all clean fclean re