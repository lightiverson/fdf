/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:23 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/03/28 13:45:24 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

int				get_map_fd(const char *map_name);
unsigned int	count_columns(const char *map_name);
unsigned int	count_rows(const char *map_name);
unsigned int	calc_distance_nodes_x(unsigned int columns);
unsigned int	calc_distance_nodes_y(unsigned int rows);

#endif /* GETS_H */