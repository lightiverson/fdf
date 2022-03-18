#include "fdf.h"

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

void	paint_nodes(t_fdf_data *fdf_data)
{
	unsigned int	i;
	t_data			img;
	
	create_mlx_image(&img);
	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		my_mlx_pixel_put(&img, fdf_data->nodes[i].x, fdf_data->nodes[i].y, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

int	main(int argc, char *argv[])
{
	t_fdf_data	fdf_data;

	is_argc_two(argc);
	parser(&fdf_data, argv[1]);

	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n", fdf_data.number_of_nodes);
	printf("\n");

	t_data img;
	create_mlx_image(&img);

	plot_lines_horizontally(&fdf_data, &img);
	plot_lines_vertically(&fdf_data, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);

	return (0);
}
