/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_breezy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 12:07:53 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/23 13:34:47 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free_breezy.h"

void	free_splitted_str(char **splitted_str)
{
	size_t	i;

	i = 0;
	while (splitted_str[i] != NULL)
	{
		free(splitted_str[i]);
		i++;
	}
	free(splitted_str);
}

void	free_nodes(t_node *nodes)
{
	return ;
}
