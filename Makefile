# Variables

NAME = fdf
VPATH =	./:\
		src:\
		src/get_next_line:\
CFLAGS = -Wall -Wextra # -Werror
LIBMLX = src/MLX42
LIBFT = src/libft

HEADERS = -I ./src -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
OBJS =	fdf.o \
		free_breezy.o \
		gets.o \
		nodes.o \
		get_next_line.o \
		get_next_line_utils.o \
		parser.o \
		plot_lines.o

#  Recipes

all: libft libmlx $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

libmlx:
	$(MAKE) -C $(LIBMLX)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBMLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	rm -f $(LIBMLX)/libmlx42.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft