objects	=	get_map.o \
			get_next_line.o \
			get_next_line_utils.o
libft	=	libft/libft.a

fdf : $(objects) $(libft)
	cc -o fdf $(objects) $(libft)

$(libft) :
	make -C libft

get_map.o : get_map.c get_map.h
	cc -c get_map.c

get_next_line.o : get_next_line/get_next_line.c get_next_line/get_next_line.h
	cc -c get_next_line/get_next_line.c

get_next_line_utils.o : get_next_line/get_next_line_utils.c get_next_line/get_next_line.h
	cc -c get_next_line/get_next_line_utils.c

clean :
	rm $(objects)
	make fclean -C libft

fclean : clean
	rm fdf

re: fclean all

.PHONY: all clean fclean re

# get_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a