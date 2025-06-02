SRC =	core/so_long.c core/game_init.c \
		gameplay/frame_update.c gameplay/handles.c gameplay/player_update.c \
		gameplay/traj_calc_xoy.c gameplay/traj_calc_yox.c gameplay/collect.c \
		gameplay/exit.c \
		parsing/check_path.c parsing/ckeck_map.c parsing/fill_background.c \
		parsing/ft_split_join.c parsing/get_next_line.c parsing/parser.c \
		parsing/tiles.c parsing/get_pos.c \
		render/img.c render/pixel.c render/put_img_to_img.c \
		utils/errors.c utils/free.c utils/math.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./includes -I./libft -I./minilibx

LDFLAGS = -L./libft -L./minilibx

LDLIBS = -lft -lmlx -lXext -lX11 -lm

NAME = so_long

DEBUG = debug

LIBFT = libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc -v $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)
	make clean

$(DEBUG): $(SRC)
	make -C $(LIBFT)
	cc $(CFLAGS) -g3 $(SRC) -o $(DEBUG) $(LDFLAGS) $(LDLIBS)
	make clean

clean:
	rm -f */*.o
	rm -f $(LIBFT)/libft.a

fclean: clean
	rm -f $(NAME) $(DEBUG)

re: fclean all

.PHONY: all clean fclean re debug
