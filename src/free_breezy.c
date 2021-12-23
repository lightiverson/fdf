#include "free_breezy.h"

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

void	free_matrix(int **calloced_matrix, unsigned int rows)
{
	unsigned int	i;

	i = 0;
	while (i < rows)
	{
		free(calloced_matrix[i]);
		i++;
	}
	free(calloced_matrix);
}