#include "fdf.h"

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: Incorrect amount of arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	print_matrix(int **matrix, unsigned int rows, unsigned int columns)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		while (j < columns)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int main(int argc, char *argv[])
{
    t_matrix_data matrix_data;

	is_argc_two(argc);
    parser(&matrix_data, argv[1]);

	printf("matrix.data.rows = %d\n", matrix_data.rows);
	printf("matrix.data.columns = %d\n", matrix_data.columns);
	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);
	printf("\n");

	t_node *nodes;
	nodes = calloc_nodes(matrix_data.rows * matrix_data.columns);
	populate_nodes(nodes, matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	// int** nodes;
	// nodes = calloc_nodes(matrix_data.rows * matrix_data.columns);
	// populate_nodes(nodes, matrix_data.matrix, matrix_data.rows, matrix_data.columns);

	t_data	img;
	create_mlx_image(&img);

	unsigned int i = 0;
	while (i < matrix_data.rows * matrix_data.columns)
	{
		my_mlx_pixel_put(&img, nodes[i].x, nodes[i].y, 0x00FF0000);
		i++;
	}

	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);

	free_matrix(matrix_data.matrix, matrix_data.rows);
    return (0);
}

// int main(int argc, char *argv[])
// {
//     t_matrix_data matrix_data;

// 	is_argc_two(argc);
//     parser(&matrix_data, argv[1]);

// 	printf("matrix.data.rows = %d\n", matrix_data.rows);
// 	printf("matrix.data.columns = %d\n", matrix_data.columns);
// 	printf("\n");
// 	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);
// 	printf("\n");

// 	int** nodes;
// 	nodes = calloc_nodes(matrix_data.rows * matrix_data.columns);
// 	populate_nodes(nodes, matrix_data.matrix, matrix_data.rows, matrix_data.columns);

// 	t_data	img;
// 	create_mlx_image(&img);

// 	unsigned int i = 0;
// 	while (i < matrix_data.rows * matrix_data.columns)
// 	{
// 		my_mlx_pixel_put(&img, nodes[i][0], nodes[i][1], 0x00FF0000);
// 		i++;
// 	}

// 	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
// 	mlx_loop(img.mlx);

// 	free_matrix(matrix_data.matrix, matrix_data.rows);
//     return (0);
// }

// int main(int argc, char *argv[])
// {
//     t_matrix_data matrix_data;

// 	is_argc_two(argc);
//     parser(&matrix_data, argv[1]);

// 	t_data	img;
// 	create_mlx_image(&img);
// 	unsigned int horizontal_line_length_px = (WINDOW_WIDTH - 1) / (matrix_data.columns - 1);
// 	unsigned int vertical_line_lenght_px = (WINDOW_HEIGHT - 1) / (matrix_data.rows - 1);
// 	unsigned int i = 0;
// 	unsigned int j = 0;
	
// 	int k = 0;
// 	while (i < matrix_data.columns)
// 	{
// 		int x = i * horizontal_line_length_px;
// 		while (j < matrix_data.rows)
// 		{
// 			int y = j * vertical_line_lenght_px;

// 			while (k < x)
// 			{
// 				my_mlx_pixel_put(&img, k, y, 0x00FF0000);
// 				k++;
// 			}
// 			k = 0;

// 			while (k < y)
// 			{
// 				my_mlx_pixel_put(&img, x, k, 0x00FF0000);
// 				k++;
// 			}
// 			k = 0;

// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
// 	mlx_loop(img.mlx);

// 	free_matrix(matrix_data.matrix, matrix_data.rows);
//     return (0);
// }
