UNAME := $(shell uname)
VPATH =	./:\
		src:\
		src/get_next_line:\
		src/my_mlx
CFLAGS = -Wall -Wextra
ifeq ($(UNAME), Linux)
CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=leak
endif

mac_os_api = -L./src/mlx -framework OpenGL -framework AppKit
objects	=	fdf.o \
			free_breezy.o \
			gets.o \
			my_mlx.o \
			nodes.o \
			get_next_line.o \
			get_next_line_utils.o \
			edges.o \
			plot_line_low.o
libft	=	src/libft/libft.a
mlx = libmlx.dylib

fdf : $(objects) $(libft) $(mlx)
	$(CC) $(CFLAGS) $(mac_os_api) -Imlx -o fdf $(objects) $(libft) $(mlx)

fdf.o : fdf.h
free_breezy.o: free_breezy.h
gets.o : gets.h
my_mlx.o : my_mlx.h
nodes.o : nodes.h
get_next_line.o : get_next_line.h
get_next_line_utils.o : get_next_line.h
edges.o : edges.h
plot_line_low.o : plot_line_low.h

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