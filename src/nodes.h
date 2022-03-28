/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nodes.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:46:10 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/03/28 13:47:39 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H

/* Public libraries */
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "gets.h"

typedef struct s_iterators {
	unsigned int	row;
	unsigned int	column;
	unsigned int	i;
}	t_iterators;

t_node	*calloc_nodes(unsigned int number_of_nodes);
void	populate_nodes(const char *map_name, t_node *nodes);
void	transform_nodes(t_fdf_data *fdf_data);

#endif /* NODES_H */