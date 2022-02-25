#ifndef MY_MLX_H
# define MY_MLX_H

# include "./mlx/mlx.h"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define MAP_WIDTH 800
# define MAP_HEIGHT 800

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_mlx_image(t_data *img);

#endif /* MY_MLX_H */