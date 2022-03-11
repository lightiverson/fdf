#ifndef GETS_H
# define GETS_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <fcntl.h>

/* Private libraries */
# include "get_next_line/get_next_line.h"
# include "free_breezy.h"
# include "my_mlx.h"

int				get_map_fd(const char *map_name);
unsigned int	count_columns(const char *map_name);
unsigned int	count_rows(const char *map_name);
unsigned int	calc_distance_columns(unsigned int columns);
unsigned int	calc_distance_rows(unsigned int rows);

#endif /* GETS_H */