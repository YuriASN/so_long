NAME = so_long

SRC = so_long.c init.c get_map.c sl_quit.c mlx_utils.c game_start.c \
	moves.c is_component.c events.c

OBJ = $(SRC: .c=.o)

CC = gcc
FALGS = -Wall -Wextra -Werror
MLX = -lbsd -lmlx -lX11 -lXext

all: $(NAME)

$(NAME):
	@make bonus -Clibft/ --no-print-directory
	@$(CC) $(FLAGS) $(SRC) -g -fsanitize=address -Llibft -lft -o $(NAME) $(MLX)
	@echo "\033[92mProgram compiled!\033[m"

clean:
	@make clean -Clibft/ --no-print-directory
	@/bin/rm -f *.o
	@echo "\033[93mclean done for all.\033[m"

fclean: clean
	@make fclean -Clibft/ --no-print-directory
	@/bin/rm -f $(NAME) libft.h.gch libft.so
	@echo "\033[93mfclean done for all.\033[m"
	
re: fclean all