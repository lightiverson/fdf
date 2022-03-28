/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:47:59 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/03/28 13:48:00 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"
# include "gets.h"
# include "nodes.h"

void	parser(t_fdf_data *fdf_data, const char *map_name);

#endif /* PARSER_H */