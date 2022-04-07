/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nodes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:45:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/03/28 13:45:45 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#define WIDTH 1000
#define HEIGHT 1000

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

void handle_str(char *word, t_iterators *iterators, t_node *nodes)
{
	char *str;
	char *endptr;
	int base;
	long val;

	str = word;
	base = 10;
	errno = 0; /* To distinguish success/failure after call */
	val = strtol(str, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	if (endptr == str) {
		fprintf(stderr, "No digits were found\n");
		exit(EXIT_FAILURE);
	}

	/* If we got here, strtol() successfully parsed a number */

	/* printf("strtol() returned %ld\n", val); */

	/* Not necessarily an error... */
	// if (*endptr != '\0') {
	// 	printf("Further characters after number: %s\n", endptr);
	// }

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

void	transform_nodes(t_fdf_data *fdf_data)
{
	unsigned int	i;
	unsigned int	distance_nodes_x;
	unsigned int	distance_nodes_y;

	distance_nodes_x = calc_distance_nodes_x(fdf_data->columns);
	distance_nodes_y = calc_distance_nodes_y(fdf_data->rows);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x * distance_nodes_x + ((WIDTH - (distance_nodes_x * fdf_data->columns - 1)) / 2);
		fdf_data->nodes[i].y = fdf_data->nodes[i].y * distance_nodes_y + ((HEIGHT - (distance_nodes_y * fdf_data->rows - 1)) / 2);
		i++;
	}
}
