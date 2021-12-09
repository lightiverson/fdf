#ifndef GETS_H
#define GETS_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int	get_rows(const char *map_name);
unsigned int	get_columns(const char *map_name);

#endif /* GETS_H */