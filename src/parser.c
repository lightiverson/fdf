/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/24 12:24:33 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Error: open()");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

static t_node	*malloc_nodes(unsigned int number_of_nodes)
{
	t_node	*nodes;

	nodes = malloc(number_of_nodes * sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	return (nodes);
}

static void	assign_nodes(const char *line, t_node *nodes,
	t_iterators *iterators)
{
	char	**words;

	iterators->column = 0;
	words = ft_split(line, ' ');
	if (words == NULL)
	{
		perror("Error: ft_split() ");
		exit(EXIT_FAILURE);
	}
	while (words[iterators->column] != NULL)
	{
		nodes[iterators->i].x = iterators->column;
		nodes[iterators->i].y = iterators->row;
		nodes[iterators->i].z = ft_atoi(words[iterators->column]);
		iterators->i++;
		iterators->column++;
	}
	free_splitted_str(words);
}

static void	populate_nodes(t_fdf_data *fdf_data)
{
	t_iterators	iterators;
	char		**lines;

	iterators.row = 0;
	iterators.i = 0;
	lines = ft_split(fdf_data->file_str, '\n');
	if (lines == NULL)
	{
		perror("Error: ft_split() ");
		exit(EXIT_FAILURE);
	}
	while (lines[iterators.row] != NULL)
	{
		assign_nodes(lines[iterators.row], fdf_data->nodes, &iterators);
		iterators.row++;
	}
	free_splitted_str(lines);
}

void	parser(t_fdf_data *fdf_data, const char *map_name)
{
	int	map_fd;
	int	r_file_to_str;

	map_fd = get_map_fd(map_name);
	r_file_to_str = file_to_str(map_fd, &fdf_data->file_str);
	if (r_file_to_str == -1)
	{
		perror("Error: file_to_str() ");
		exit(EXIT_FAILURE);
	}
	close(map_fd);
	fdf_data->rows = count_rows(fdf_data->file_str);
	fdf_data->columns = count_columns(fdf_data->file_str);
	fdf_data->number_of_nodes = fdf_data->rows * fdf_data->columns;
	fdf_data->nodes = malloc_nodes(fdf_data->number_of_nodes);
	populate_nodes(fdf_data);
	free(fdf_data->file_str);
}
