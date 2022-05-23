/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_to_str.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 11:59:21 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/23 13:30:00 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TO_STR_H
# define FILE_TO_STR_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>

/* Private libraries */
# include "libft/libft.h"

int	file_to_str(int fd, char **file_str);

#endif /* FILE_TO_STR_H */
