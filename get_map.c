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
	return (rows);
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

int *calloc_matrix(unsigned int rows, unsigned int columns)
{
	int *matrix;

	matrix = ft_calloc(rows * columns, sizeof(*matrix));
	if (matrix == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (matrix);
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


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
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

	int i = 0;
	int j = 0;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);

	while (i < 9)
	{
		while (j < 11)
		{
			// printf("%d ", matrix[i][j]);
			// printf("(%d, %d) ", i, j);
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		// printf("\n");
		j = 0;
		i++;
	}
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 6, 6, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 7, 7, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 8, 8, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 9, 9, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}