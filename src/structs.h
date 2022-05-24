/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 14:01:27 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/24 12:25:28 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node {
	int		x;
	int		y;
	int		z;
}	t_node;

typedef struct s_fdf_data {
	char			*file_str;
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	number_of_nodes;
	t_node			*nodes;
}	t_fdf_data;

#endif /* STRUCTS_H */