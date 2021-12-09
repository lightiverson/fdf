UNAME := $(shell uname)
VPATH = ./:get_next_line
CFLAGS = -Wall -Wextra
ifeq ($(UNAME), Linux)
CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=leak
endif

mac_os_api = -Lmlx -framework OpenGL -framework AppKit
objects	=	fdf.o \
			get_next_line.o \
			get_next_line_utils.o \
			matrix.o \
			gets.o \
			my_mlx.o
libft	=	libft/libft.a
mlx = libmlx.dylib

fdf : $(objects) $(libft) $(mlx)
	$(CC) $(CFLAGS) $(mac_os_api) -Imlx -o fdf $(objects) $(libft) $(mlx)

fdf.o : fdf.h
get_next_line.o : get_next_line.h
get_next_line_utils.o : get_next_line.h
matrix.o : matrix.h
gets.o : gets.h
my_mlx.o : my_mlx.h

$(libft) :
	make -C libft

$(mlx):
	make -C mlx
	mv mlx/$(mlx) .

clean :
	rm -f $(objects)
	make clean -C libft
	make clean -C mlx

fclean : clean
	rm -f fdf
	make fclean -C libft
	rm -f $(mlx)

re: fclean all

.PHONY: all clean fclean re

# gcc -Wall -Wextra -g -fsanitize=address -fsanitize=leak fdf.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a
# gcc -Wall -Wextra -g fdf.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a
# valgrind --leak-check=full ./a.out