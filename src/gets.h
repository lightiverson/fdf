#ifndef GETS_H
# define GETS_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "free_breezy.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "my_mlx.h"

void			free_splitted_array(char **splitted_array);
int				get_map_fd(const char *map_name);
unsigned int	count_columns(const char *map_name);
unsigned int	count_rows(const char *map_name);
unsigned int get_distance_between_columns(unsigned int columns);
unsigned int get_distance_between_rows(unsigned int rows);

#endif /* GETS_H */