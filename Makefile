NAME =			so_long
LIB =			so_long.h
LIBFT_DIR =		../libft_new
LIBFT =			../libft_new/libft.a
LIBMLX_DIR =		./mlx_linux
MLX_INCLUDE = 	-Imlx_linux
SRC =			main.c maps.c validate_map.c utils.c window.c \
				utils_free.c images.c movement.c enemy.c
SRC_OBJS =		$(SRC:.c=.o)
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g
MLX_FLAGS = 	-L$(LIBMLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(SRC) 
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@$(CC) $(^) $(MLX_FLAGS) -o $(@) $(LIBFT) -fsanitize=address

clean:
			@rm -f $(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR) clean

re:			fclean all

.PHONY: all clean fclean re