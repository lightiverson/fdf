#include "parser.h"

void	parser(t_fdf_data *fdf_data, const char *map_name)
{
	fdf_data->rows = count_rows(map_name);
	fdf_data->columns = count_columns(map_name);
	fdf_data->number_of_nodes = fdf_data->rows * fdf_data->columns;
	fdf_data->number_of_edges = fdf_data->number_of_nodes - 1;
	fdf_data->nodes = calloc_nodes(fdf_data->number_of_nodes);
	populate_nodes(map_name, fdf_data->nodes);
	transform_nodes(fdf_data);
}