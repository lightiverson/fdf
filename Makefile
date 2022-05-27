NAME := fdf
HEADERS :=	src/fdf.h \
			src/file_to_str.h \
			src/parser.h \
			src/plot_lines.h \
			src/plot_nodes.h \
			src/rotate.h \
			src/screen_raster_sizes.h \
			src/structs.h \
			src/translate_nodes.h \
			src/translate_raster.h \
			src/utilities.h
OBJECTS :=	obj/fdf.o \
			obj/file_to_str.o \
			obj/parser.o \
			obj/parser_cont.o \
			obj/plot_lines.o \
			obj/plot_nodes.o \
			obj/rotate.o \
			obj/translate_nodes.o \
			obj/translate_raster.o \
			obj/translate_raster_cont.o \
			obj/utilities.o
CFLAGS ?= -Wall -Wextra -Werror
LDFLAGS ?=
LIBFT := src/libft
LIBMLX := src/MLX42
LIBGLFW := -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

all : libft libmlx $(NAME)

libft:
	make -C $(LIBFT)

libmlx:
	make -C $(LIBMLX)

$(NAME) : $(OBJECTS)
	cc $(LDFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a $(LIBGLFW)

obj/%.o : src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	cc -c $(CFLAGS) -o $@ $<

clean :
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)
	rm -f $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMLX)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re libft libmlx