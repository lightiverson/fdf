/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:46:10 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/08/18 10:12:38 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Public libraries */
# include <fcntl.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "utilities.h"
# include "file_to_str.h"

typedef struct s_iterators {
	size_t	row;
	size_t	column;
	size_t	i;
}	t_iterators;

int				get_map_fd(const char *map_name);
unsigned int	count_rows(char *file_str);
unsigned int	count_columns(char *file_str);
void			parser(t_fdf_data *fdf_data, const char *map_name);

#endif /* PARSER_H */