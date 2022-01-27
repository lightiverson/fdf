#include "fdf.h"

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: not the right amount of args\n");
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

// int main (void)
// {
// 	int **nodes;
// 	int i = 0;
// 	int j = 0;

// 	nodes = calloc(2, sizeof(*nodes));
// 	while (i < 2)
// 	{
// 		nodes[i] = calloc(3, sizeof(nodes[i]));
// 		i++;
// 	}

// 	nodes[0][0] = -100;
// 	nodes[0][1] = -110;
// 	nodes[0][2] = -120;

// 	nodes[1][0] = -30;
// 	nodes[1][1] = 40;
// 	nodes[1][2] = -50;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		printf("nodes[%d] = ", i);
// 		while (j < 3)
// 		{
// 			printf("%d ", nodes[i][j]);
// 			j++;
// 		}
// 		j = 0;
// 		printf("\n");
// 		i++;
// 	}
	

	int node0[3] = {-100, -100, -100};
	int node1[3] = {-100, 100, -100};
	int *nodes[2] = {node0, node1};
// }

int main(void)
{
	const char *map_name = "./test_maps/basictest.fdf";
    t_matrix_data matrix_data;

    parser(&matrix_data, map_name);

	printf("matrix.data.rows = %d\n", matrix_data.rows);
	printf("matrix.data.columns = %d\n", matrix_data.columns);
	printf("\n");
	print_matrix(matrix_data.matrix, matrix_data.rows, matrix_data.columns);
	printf("\n");

	t_data	img;
	create_mlx_image(&img);
	unsigned int horizontal_line_length_px = (WIDTH - 1) / (matrix_data.columns - 1);
	unsigned int vertical_line_lenght_px = (HEIGHT - 1) / (matrix_data.rows - 1);
	unsigned int i = 0;
	unsigned int j = 0;
	
	int k = 0;
	while (i < matrix_data.columns)
	{
		int x = i * horizontal_line_length_px;
		while (j < matrix_data.rows)
		{
			int y = j * vertical_line_lenght_px;

			while (k < x)
			{
				my_mlx_pixel_put(&img, k, y, 0x00FF0000);
				k++;
			}
			k = 0;

			while (k < y)
			{
				my_mlx_pixel_put(&img, x, k, 0x00FF0000);
				k++;
			}
			k = 0;

			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);

	free_matrix(matrix_data.matrix, matrix_data.rows);
    return (0);
}

// int	main(void)
// {
// 	int **m = create_matrix("./test_maps/basictest.fdf");
// 	print_matrix(m, 9, 11);
// 	t_data	img;
// 	int matrix[9][11] = 
// 	{
// 		{0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
// 		{0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8},
// 		{0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7},
// 		{0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6},
// 		{0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5},
// 		{0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4},
// 		{0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3},
// 		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
// 		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
// 	};

// 	create_mlx_image(&img);

// 	int horizontal_line_length_px = (WIDTH - 1) / 10;
// 	int vertical_line_lenght_px = (HEIGHT - 1) / 8;

// 	int i = 0;
// 	int j = 0;
// 	while (i < 11)
// 	{
// 		while (j < 9)
// 		{
// 			my_mlx_pixel_put(&img, i * horizontal_line_length_px, j * vertical_line_lenght_px, 0x00FF0000);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
// 	mlx_loop(img.mlx);
// }