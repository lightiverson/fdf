#include "nodes.h"
#include "gets.h"

t_node *calloc_nodes(unsigned int number_of_nodes)
{
	t_node *nodes;

	nodes = calloc(number_of_nodes, sizeof(*nodes));
	if (nodes == NULL)
	{
		perror("Error: malloc() ");
		exit(EXIT_FAILURE);
	}
	return (nodes);
}

unsigned int get_distance_between_nodes_in_px(unsigned int columns)
{
	unsigned int max_distance;
	unsigned int distance_between_nodes_in_px;

	max_distance = 20;
	distance_between_nodes_in_px = MAP_WIDTH / columns;
	if (distance_between_nodes_in_px > max_distance)
		distance_between_nodes_in_px = max_distance;

	return (distance_between_nodes_in_px);
}

static void	handle_str(char *vertex_str, unsigned int row,
			unsigned int column, t_node *nodes, unsigned int *i)
{
	int		base;
	char	*endptr;
	char	*str;
	long	val;

	str = vertex_str;
	base = 10;
	errno = 0;  /* To distinguish success/failure after call */
	val = strtol(str, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
			|| (errno != 0 && val == 0)) {
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
	if (*endptr != '\0') {
		printf("Further characters after number: %s\n", endptr);
	}

	nodes[*i].x = column;
	nodes[*i].y = row;
	nodes[*i].z = val;
	(*i)++;
}

static void	iterate_over_columns(const char *line, unsigned int row, t_node *nodes, unsigned int *i)
{
	char			**vertex;
	unsigned int	column;

	vertex = ft_split(line, ' ');
	column = 0;
	while (vertex[column] != NULL)
	{
		handle_str(vertex[column], row, column, nodes, i);
		column++;
	}
	free_splitted_array(vertex);
}

void	populate_nodes(const char *map_name, t_node *nodes)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	row;

	map_fd = get_map_fd(map_name);
	return_get_next_line = 1;
	row = 0;
	unsigned int i = 0;
	while (return_get_next_line)
	{
		return_get_next_line = get_next_line(map_fd, &line);
		if (return_get_next_line == -1)
		{
			free(line);
			printf("Error: get_next_line returned -1\n");
			exit(EXIT_FAILURE);
		}
		iterate_over_columns(line, row, nodes, &i);
		if (line[0] == '\0')
			continue ;
		row++;
		free(line);
	}
	close(map_fd);
}

void parser(t_fdf_data *fdf_data, const char *map_name)
{
	fdf_data->rows = get_rows(map_name);
	fdf_data->columns = get_columns(map_name);
	fdf_data->number_of_nodes = fdf_data->rows * fdf_data->columns;
	fdf_data->nodes = calloc_nodes(fdf_data->number_of_nodes);
	populate_nodes(map_name, fdf_data->nodes);
}