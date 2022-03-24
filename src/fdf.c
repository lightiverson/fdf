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

void	plot_nodes(t_fdf_data *fdf_data, mlx_image_t *g_img)
{
	unsigned int	i;

	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		mlx_put_pixel(g_img, fdf_data->nodes[i].x, fdf_data->nodes[i].y, 0xFF0000FF);
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

	// Setup MLX42
	mlx_t	*mlx;

	mlx = mlx_init(1000, 1000, "FDF", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 800, 800); // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0); // Adds an image to the render queue.

	plot_lines_horizontally(&fdf_data, g_img);
	plot_lines_vertically(&fdf_data, g_img);
	plot_nodes(&fdf_data, g_img);

	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}