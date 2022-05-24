/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_cont.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 15:13:07 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/24 15:14:20 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_first_line(char *file_str)
{
	char			*first_line;
	unsigned int	len_first_line;
	size_t			i;

	len_first_line = 0;
	i = 0;
	while (file_str[i] != '\n')
	{
		len_first_line++;
		i++;
	}
	first_line = malloc((len_first_line + 1) * sizeof(*first_line));
	if (first_line == NULL)
	{
		printf("Malloc failed. Exiting...");
		exit(1);
	}
	ft_strlcpy(first_line, file_str, len_first_line + 1);
	return (first_line);
}

unsigned int	count_columns(char *file_str)
{
	size_t			i;
	unsigned int	number_of_columns;
	char			*first_line;
	char			**splitted_strings;

	i = 0;
	number_of_columns = 0;
	first_line = get_first_line(file_str);
	splitted_strings = ft_split(first_line, ' ');
	if (splitted_strings == NULL)
	{
		printf("Split() failed. Exiting...");
		exit(1);
	}
	while (splitted_strings[i] != NULL)
	{
		number_of_columns++;
		i++;
	}
	free_splitted_str(splitted_strings);
	free(first_line);
	return (number_of_columns);
}

unsigned int	count_rows(char *file_str)
{
	size_t			i;
	unsigned int	number_of_rows;

	number_of_rows = 1;
	i = 0;
	while (file_str[i] != '\0')
	{
		if (file_str[i] == '\n')
			number_of_rows++;
		i++;
	}
	if (file_str[i - 1] == '\n')
		number_of_rows--;
	return (number_of_rows);
}
