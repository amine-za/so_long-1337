NAME = so_long

SRCS = so_long.c so_long_utils.c so_long_utils2.c key_event.c check_map.c door_condition.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
# SRCS = *.c ./gnl/*.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	CC -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean : 
	@rm -rf *.o ./gnl/get_next_line.o ./gnl/get_next_line_utils.o

fclean : clean
	@rm -rf so_long

re : fclean all