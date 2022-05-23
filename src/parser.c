/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/23 13:13:33 by kgajadie      ########   odam.nl         */
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

// void	populate_nodes(const char *map_name, t_node *nodes)
// {
// 	int			map_fd;
// 	int			bytes_read;
// 	char		*line;
// 	t_iterators	iterators;

// 	map_fd = get_map_fd(map_name);
// 	bytes_read = 1;
// 	iterators.row = 0;
// 	iterators.i = 0;
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = get_next_line(map_fd, &line);
// 		iterate_over_columns(line, nodes, &iterators);
// 		if (line[0] == '\0')
// 			continue ;
// 		iterators.row++;
// 		free(line);
// 	}
// 	if (bytes_read == -1)
// 	{
// 		printf("Error: get_next_line returned -1\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(map_fd);
// }

void alpha(char *line, t_node *nodes, t_iterators *iterators)
{
	size_t j;
	char **words;

	j = 0;
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
	free_splitted_array(words);
}

void	populate_nodes(t_fdf_data *fdf_data)
{
	t_iterators iterators;

	iterators.row = 0;
	iterators.i = 0;
	char **lines = ft_split(fdf_data->file_str, '\n');
	if (lines == NULL)
	{
		perror("Error: ft_split() ");
		exit(EXIT_FAILURE);
	}
	while (lines[iterators.row] != NULL)
	{
		alpha(lines[iterators.row], fdf_data->nodes, &iterators);
		iterators.row++;
	}
	free_splitted_array(lines);

	// while (i < fdf_data->number_of_nodes)
	// {
	// 	fdf_data->nodes[i].x = i % fdf_data->columns;
	// 	fdf_data->nodes[i].y = i / fdf_data->columns;
	// 	fdf_data->nodes[i].z = fdf_data->file_str[i];
	// 	i++;
	// }
}

void	parser(t_fdf_data *fdf_data, const char *map_name)
{
	int	map_fd;
	int r_file_to_str;

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
	fdf_data->nodes = calloc_nodes(fdf_data->number_of_nodes);
	populate_nodes(fdf_data);
}
