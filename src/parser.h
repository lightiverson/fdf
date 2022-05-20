/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:46:10 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/20 18:01:07 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Public libraries */
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "gets.h"
# include "screen_raster_sizes.h"
# include "free_breezy.h"
# include "utilities.h"
# include "get_next_line/get_next_line.h"
# include "file_to_str.h"

typedef struct s_iterators {
	unsigned int	row;
	unsigned int	column;
	unsigned int	i;
}	t_iterators;

t_node	*calloc_nodes(unsigned int number_of_nodes);
void	populate_nodes(const char *map_name, t_node *nodes);
void	translate_nodes(t_fdf_data *fdf_data);
void	parser(t_fdf_data *fdf_data, const char *map_name);

#endif /* PARSER_H */