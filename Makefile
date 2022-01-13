UNAME := $(shell uname)
VPATH =	./:\
		src:\
		src/fdf:\
		src/get_next_line:\
		src/gets:\
		src/matrix:\
		src/my_mlx
CFLAGS = -Wall -Wextra
ifeq ($(UNAME), Linux)
CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=leak
endif

mac_os_api = -L./src/mlx -framework OpenGL -framework AppKit
objects	=	fdf.o \
			get_next_line.o \
			get_next_line_utils.o \
			matrix.o \
			gets.o \
			my_mlx.o
libft	=	src/libft/libft.a
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
	make -C ./src/libft

$(mlx):
	make -C ./src/mlx
	mv ./src/mlx/$(mlx) .

clean :
	rm -f $(objects)
	make clean -C ./src/libft
	make clean -C ./src/mlx

fclean : clean
	rm -f fdf
	make fclean -C ./src/libft
	rm -f $(mlx)

re: fclean all

.PHONY: all clean fclean re