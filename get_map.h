#ifndef GET_MAP_H
#define GET_MAP_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#include "mlx/mlx.h"

#define WIDTH 1280
#define HEIGHT 720

// struct voor mlx
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

#endif /* GET_MAP_H */