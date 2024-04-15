SRCS	= main.c \
		  src/struct_init.c \
		  src/get_next_line.c \
		  src/get_next_line_utils.c \
		  src/map.c

OBJS	= $(SRCS:.c=.o)

NAME	= cub3d

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

RM		= rm -rf

MLX		=	mlx_linux/libmlx_Linux.a

MLX_LIB_DIR = mlx_linux/

MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
		$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

$(MLX):
		make -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $^ -o $@


clean: 
	$(RM) $(OBJS)
	make clean -C mlx_linux

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re