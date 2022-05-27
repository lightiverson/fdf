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
CFLAGS ?= -Wall -Wextra -Werror # CFLAGS = compiler flags
LDFLAGS ?= # LDFLAGS = linker flags

all : $(NAME)

$(NAME) : $(OBJECTS)
	cc $(LDFLAGS) -o $(NAME) $(OBJECTS)

obj/%.o : src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	cc -c $(CFLAGS) -o $@ $<

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re