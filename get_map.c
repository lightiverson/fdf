#include "get_map.h"
#include <assert.h>

void	free_splitted_array(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i] != NULL)
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}

void	is_argc_two(int argc)
{
	if (argc != 2)
	{
		printf("Error: not the right amount of args\n");
		exit(EXIT_FAILURE);
	}
}

int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

unsigned int	get_rows(const char *map_name)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	rows;

	map_fd = get_map_fd(map_name);
	return_get_next_line = 1;
	rows = 0;
	while (return_get_next_line)
	{
		return_get_next_line = get_next_line(map_fd, &line);
		if (return_get_next_line == -1)
		{
			free(line);
			printf("Error: get_next_line returned -1\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		rows++;
	}
	close(map_fd);
	return (rows - 1);
}

unsigned int	get_columns(const char *map_name)
{
	int				map_fd;
	int				return_get_next_line;
	char			*line;
	unsigned int	columns;
	char			**vertex;

	map_fd = get_map_fd(map_name);
	columns = 0;
	return_get_next_line = get_next_line(map_fd, &line);
	if (return_get_next_line == -1)
	{
		free(line);
		printf("Error: get_next_line returned -1\n");
		exit(EXIT_FAILURE);
	}
	vertex = ft_split(line, ' ');
	while (vertex[columns] != NULL)
		columns++;
	free_splitted_array(vertex);
	close(map_fd);
	return (columns);
}

int **calloc_matrix(unsigned int rows, unsigned int columns)
{
	int **matrix;

	// matrix = ft_calloc(rows, sizeof(*matrix));
	matrix = ft_calloc(rows, sizeof(int*));
	if (matrix == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	unsigned int i = 0;
	while (i < rows)
	{
		matrix[i] = ft_calloc(columns, sizeof(int));
		if (matrix[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (matrix);
}

int **create_matrix(char *map_name)
{
	unsigned int	rows;
	unsigned int	columns;
	int				**matrix;

	rows = get_rows(map_name);
	printf("rows = %d\n", rows);

	columns = get_columns(map_name);
	printf("columns = %d\n", columns);

	matrix = calloc_matrix(rows, columns);
	return (matrix);
}

void print_matrix(int **matrix, unsigned int rows, unsigned int columns)
{
	unsigned int i;
	unsigned int j;

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

/*
dit wil ik uiteindelijke krijgen:
	   x  y
matrix[0][0] = 0
matrix[1][0] = 0
matrix[2][0] = 1
matrix[3][0] = 2
matrix[4][0] = 3
matrix[5][0] = 4
matrix[6][0] = 5
matrix[7][0] = 6
matrix[8][0] = 7
matrix[9][0] = 8
matrix[10][0] = 9
 */

// int main(int argc, char const *argv[])
// {
// 	unsigned int	rows;
// 	unsigned int	columns;
// 	int				*matrix;

// 	rows = get_rows("./test_maps/basictest.fdf");
// 	printf("rows = %d\n", rows);

// 	columns = get_columns("./test_maps/basictest.fdf");
// 	printf("columns = %d\n", columns);

// 	matrix = calloc_matrix(rows, columns);

// 	int				map_fd;
// 	int				return_get_next_line;
// 	char			*line;
// 	char			**vertex;

// 	map_fd = get_map_fd("./test_maps/basictest.fdf");
// 	return_get_next_line = 1;
// 	while (return_get_next_line == 1)
// 	{
// 		return_get_next_line = get_next_line(map_fd, &line);
// 		if (return_get_next_line == -1)
// 		{
// 			free(line);
// 			printf("Error: get_next_line returned -1\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (return_get_next_line == 1)
// 		{
// 			printf("|%s|\n", line); // |0 0 1 2 3 4 5 6 7 8 9|
			
// 		}
// 		free(line);
// 	}
// 	close(map_fd);
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	main(void)
{
	int **m = create_matrix("./test_maps/basictest.fdf");
	print_matrix(m, 9, 11);
	void	*mlx;
	void	*mlx_win;
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}