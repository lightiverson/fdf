#include "degrees_to_radians.h"

double	degrees_to_radians(double degrees)
{
	double	radians;

	radians = degrees * M_PI / 180;
	return (radians);
}

// int	main(void)
// {
// 	printf("45 degrees = %f radians\n", degrees_to_radians(-45));
// 	return (0);
// }

void	rotate_node_z_axis(t_node *node)
{
	int		x_1;
	int		y_1;
	double	degrees;

	degrees = degrees_to_radians(-45);

	x_1 = (node->x * cos(degrees)) - (node->y * sin(degrees));
	printf("x_1 = %i\n", x_1);

	y_1 = (node->x * sin(degrees)) + (node->y * cos(degrees));
	printf("y_1 = %i\n", y_1);
}

void	rotate_nodes_z_axis(t_fdf_data *fdf_data)
{
	unsigned int	i;

	i = 0;
	while (i < fdf_data->number_of_nodes)
	{
		rotate_node_z_axis(fdf_data->nodes + i);
		i++;
	}
}