NAME = fractol

SOURCES = main.c fractals.c inputs.c color.c

OBJECTS = $(subst .c,.o,$(SOURCES))

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra #-Werror
LINKS = -I libft -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
	@echo "$(MSG)Done!$(END)"

$(OBJECTS): $(LIBFT) $(SOURCES)
	@echo "$(MSG)Compiling...$(END)"
	@gcc $(FLAGS) -c $(SOURCES)

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@echo "$(MSG)Objects removed!$(END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(MSG)Targets removed!$(END)"

re: fclean all
