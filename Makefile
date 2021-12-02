VPATH = ./:get_next_line
objects	=	get_map.o \
			get_next_line.o \
			get_next_line_utils.o
libft	=	libft/libft.a
CFLAGS = -Wall -Wextra -g -fsanitize=address -fsanitize=leak

fdf : $(objects) $(libft)
	$(CC) $(CFLAGS) -o fdf $(objects) $(libft)

$(libft) :
	make -C libft

get_map.o : get_map.h
get_next_line.o : get_next_line/get_next_line.h
get_next_line_utils.o : get_next_line/get_next_line.h

clean :
	rm $(objects)
	make fclean -C libft

fclean : clean
	rm fdf

re: fclean all

.PHONY: all clean fclean re

# get_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a