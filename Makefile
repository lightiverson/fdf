objects	=	get_map.o \
			get_next_line/get_next_line.o \
			get_next_line/get_next_line_utils.o
libft	=	libft/libft.a

fdf : $(objects)
	cc -o fdf $(objects) $(libft)

get_map.o : get_map.c get_map.h
	cc -c get_map.c

get_next_line.o : get_next_line/get_next_line.c get_next_line/get_next_line.h
	cc -c get_next_line/get_next_line.c

get_next_line_utils.o : get_next_line/get_next_line_utils.c get_next_line/get_next_line.h
	cc -c get_next_line/get_next_line_utils.c

clean :
	rm fdf $(objects)

# get_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/libft.a