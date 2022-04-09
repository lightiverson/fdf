/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_breezy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 12:07:53 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/04/09 14:10:52 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free_breezy.h"

void	free_splitted_array(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i] != NULL)
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}

void	free_nodes(t_node *nodes)
{
	return ;
}
