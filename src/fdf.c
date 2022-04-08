#include "fdf.h"

mlx_image_t *g_img;

void	print_nodes(t_node *nodes, unsigned int number_of_nodes)
{
	unsigned int	i;

	i = 0;
	while (i < number_of_nodes)
	{
		printf("nodes[%u] = {x: %i, y: %i, z: %i}\n",
			i, nodes[i].x, nodes[i].y, nodes[i].z);
		i++;
	}
}

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: Incorrect amount of arguments\n");
		exit(EXIT_FAILURE);
	}
}

unsigned int	calc_raster_width(t_fdf_data *fdf_data)
{
	int	left_border;
	int	right_border;
	int	raster_width;

	left_border = fdf_data->nodes[fdf_data->number_of_nodes - fdf_data->columns].x;
	printf("left_border = %i\n", left_border);

	right_border = fdf_data->nodes[fdf_data->columns - 1].x;
	printf("right_border = %i\n", right_border);

	raster_width = right_border - left_border;
	printf("raster_width = %i\n", raster_width);

	return (raster_width);
}

// unsigned int	calc_raster_height(t_fdf_data *fdf_data)

void	translate_raster(t_fdf_data *fdf_data)
{
	unsigned int	raster_width;
	unsigned int	i;

	raster_width = calc_raster_width(fdf_data);
	// raster_height = calc_raster_height(fdf_data);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		fdf_data->nodes[i].x = fdf_data->nodes[i].x;
		// fdf_data->nodes[i].x = fdf_data->nodes[i].x + ((SCREEN_W - raster_width) / 1.5);
		fdf_data->nodes[i].y = fdf_data->nodes[i].y;
		// fdf_data->nodes[i].y = fdf_data->nodes[i].y + ((SCREEN_H - raster_height) / 1.5);
		i++;
	}
}

int main(int argc, char *argv[])
{
	// Setup programma
	t_fdf_data	fdf_data;

	is_argc_two(argc);
	parser(&fdf_data, argv[1]);

	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n\n", fdf_data.number_of_nodes);
	print_nodes(fdf_data.nodes, fdf_data.number_of_nodes);

	translate_nodes(&fdf_data);
	rotate_nodes_z_axis(&fdf_data);

	print_nodes(fdf_data.nodes, fdf_data.number_of_nodes);

	translate_raster(&fdf_data);

	// Setup MLX42
	mlx_t	*mlx;

	mlx = mlx_init(SCREEN_W, SCREEN_H, "FDF", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, SCREEN_W, SCREEN_H); // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0); // Adds an image to the render queue.

	plot_lines_horizontally(&fdf_data, g_img);
	plot_lines_vertically(&fdf_data, g_img);
	plot_nodes(&fdf_data, g_img);

	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}