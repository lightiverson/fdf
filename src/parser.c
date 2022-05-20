/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/20 18:06:25 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*calloc_nodes(unsigned int number_of_nodes)
{
	t_node	*nodes;

	nodes = calloc(number_of_nodes, sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	return (nodes);
}

void	handle_str(char *word, t_iterators *iterators, t_node *nodes)
{
	int	val;

	val = ft_atoi(word);
	nodes[iterators->i].x = iterators->column;
	nodes[iterators->i].y = iterators->row;
	nodes[iterators->i].z = val;
	iterators->i++;
}

void	iterate_over_columns(const char *line,
		t_node *nodes, t_iterators *iterators)
{
	char	**words;

	words = ft_split(line, ' ');
	iterators->column = 0;
	while (words[iterators->column] != NULL)
	{
		handle_str(words[iterators->column], iterators, nodes);
		iterators->column++;
	}
	free_splitted_array(words);
}

void	populate_nodes(const char *map_name, t_node *nodes)
{
	int			map_fd;
	int			bytes_read;
	char		*line;
	t_iterators	iterators;

	map_fd = get_map_fd(map_name);
	bytes_read = 1;
	iterators.row = 0;
	iterators.i = 0;
	while (bytes_read > 0)
	{
		bytes_read = get_next_line(map_fd, &line);
		iterate_over_columns(line, nodes, &iterators);
		if (line[0] == '\0')
			continue ;
		iterators.row++;
		free(line);
	}
	if (bytes_read == -1)
	{
		printf("Error: get_next_line returned -1\n");
		exit(EXIT_FAILURE);
	}
	close(map_fd);
}

void	parser(t_fdf_data *fdf_data, const char *map_name)
{
	int	map_fd;

	map_fd = get_map_fd(map_name);
	file_to_str(map_fd, &fdf_data->file_str);
	close(map_fd);
	fdf_data->rows = count_rows(fdf_data->file_str);
	fdf_data->columns = count_columns(fdf_data->file_str);
	fdf_data->number_of_nodes = fdf_data->rows * fdf_data->columns;
	fdf_data->nodes = calloc_nodes(fdf_data->number_of_nodes);
	populate_nodes(map_name, fdf_data->nodes);
}
