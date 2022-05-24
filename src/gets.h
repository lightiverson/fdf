/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:23 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/23 13:54:14 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETS_H
# define GETS_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* Private libraries */
# include "structs.h"

int	get_smallest_x(t_fdf_data *fdf_data);
int	get_largest_x(t_fdf_data *fdf_data);
int	get_smallest_y(t_fdf_data *fdf_data);
int	get_largest_y(t_fdf_data *fdf_data);

#endif /* GETS_H */