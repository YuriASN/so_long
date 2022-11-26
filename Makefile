NAME = so_long

SRC = check_path.c map_checkers.c sl_utils.c so_long.c

OBJ = $(SRC: .c=.o)

CC = gcc
FALGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make bonus -Clibft/ --no-print-directory
	@$(CC) $(FLAGS) $(SRC) -g -fsanitize=address -Llibft -lft -o $(NAME)
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