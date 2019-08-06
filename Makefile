
#	Library
NAME = 				fractol

# 	Compiler
CC = 				gcc

#	Flags for norme + LLDB
CFLAGS = 			-Wall -Wextra -Werror -g
GFLAGS =			-lmlx -framework OpenGL -framework AppKit
#GFLAGS =			 -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11


#	Headers infos
HEA_PATH = 			./src
HEA_NAME = 			fractol.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

#	Sources infos
SRC_PATH = 			./src
SRC_NAME = 			main.c sierpinski.c julia.c julia2.c hsvrgb.c
SRC = 				$(addprefix $(SRC_PATH)/,$(SRC_NAME))

#	Objects infos
OBJ_PATH = 			./src
OBJ_NAME = 			$(SRC_NAME:.c=.o)
OBJ = 				$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


###############################################################################


all: $(NAME)

$(NAME): 			$(OBJ) $(HEA)
					@make -C libft/
					@$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)
					@echo "Fractol compilation complete."

%.o: 				%.c $(HEA)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -rf $(OBJ)
					@make -C libft clean
					@echo "Object files deleted."

fclean: 			clean
					@make -C libft fclean
					@rm -rf $(NAME)
					@echo "Executable deleted."

re: 				fclean all

.PHONY: 			all clean fclean re


###############################################################################