/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strjoin_twee.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 10:15:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/05/20 10:19:30 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../gets.h"
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strjoin_twee(char *s1, char *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	joined_str = malloc((len_s1 + len_s2 + 1 * sizeof(char)));
	if (joined_str == NULL)
		return (NULL);
	ft_strcpy(joined_str, s1);
	ft_strcpy(joined_str + len_s1, s2);
	free(s1);
	return (joined_str);
}

int	file_to_str(int fd, char **file_str)
{
	int			n;
	static char	buf[BUFSIZ + 1];

	if (fd < 0 || fd > 1024 || BUFSIZ <= 0 || !file_str)
		return (-1);
	*file_str = NULL;
	n = 1;
	while (n > 0)
	{
		*file_str = strjoin_twee(*file_str, buf);
		if (*file_str == NULL)
			return (-1);
		n = read(fd, buf, BUFSIZ);
		if (n == -1)
			return (-1);
		buf[n] = '\0';
	}
	return (0);
}

// int main(void)
// {
//     char* s1 = NULL;
//     char* s2 = "Hello World";
//     char* joined_str; 

//     joined_str = strjoin_twee(s1, s2);
//     printf("joined_str = |%s|\n", joined_str);
//     free(joined_str);
//     return (0);
// }

int main(void)
{
	int map_fd;
	char *line;

	map_fd = get_map_fd("../../test_maps/basictest.fdf");
	printf("map_fd = %i\n", map_fd);

	line = NULL;
	file_to_str(map_fd, &line);
	printf("line = \n|%s|\n", line);
	close(map_fd);
}