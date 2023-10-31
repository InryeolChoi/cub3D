NAME = cub3D
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx
CC = cc -o3 -g -Wall -Wextra -Werror -fsanitize=address
FLAG1 = -L$(MLX_DIR) -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore -o $@
FLAG2 = -L$(LIBFT_DIR) -lft
SRCS_DIR = ./srcs
SRCS = cub3d_main.c cub3d_hook.c \
		cub3d_move.c cub3d_draw.c \
		cub3d_line.c cub3d_raycast.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cp $(MLX_DIR)/libmlx.dylib .
	$(CC) $(FLAG1) $(FLAG2) $(OBJS) -o $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -rf libmlx.dylib
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re