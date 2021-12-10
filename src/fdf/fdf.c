#include "fdf.h"
#include "../matrix/matrix.h"
#include "../my_mlx/my_mlx.h"
#include <assert.h>

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: not the right amount of args\n");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	int **m = create_matrix("./test_maps/basictest.fdf");
	print_matrix(m, 9, 11);
	t_data	img;
	int matrix[9][11] = 
	{
		{0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8},
		{0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7},
		{0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6},
		{0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5},
		{0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
	};

	create_mlx_image(&img);

	int horizontal_line_length_px = (WIDTH - 1) / 10;
	int vertical_line_lenght_px = (HEIGHT - 1) / 8;

	int i = 0;
	int j = 0;
	while (i < 11)
	{
		while (j < 9)
		{
			my_mlx_pixel_put(&img, i * horizontal_line_length_px, j * vertical_line_lenght_px, 0x00FF0000);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}