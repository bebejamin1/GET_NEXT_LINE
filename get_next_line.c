/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:13 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/19 16:51:01 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*for_next_line(char *check)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check[i] != '\n' && check[i] != '\0')
		i++;
	i++;
	while (check[i] != '\0')
	{
		check[j] = check[i];
		i++;
		j++;
	}
	check[j] = '\0';
	return (check);
}

int	check_if_nline(char *check)
{
	int	i;

	i = 0;
	while (check[i] != '\n' && check[i] != '\0')
		i++;
	if (check[i] == '\n')
		return (-1);
	return (1);
}

char	*free_stock(char *str, char *buffer)
{
	char	*stock;

	stock = NULL;
	if (!str)
		str = ft_stringdup("");
	stock = ft_stringdup(str);
	free(str);
	str = ft_castjoin(stock, buffer);
	free(stock);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		reader;

	str = NULL;
	if (buffer[0] != '\0')
		str = ft_stringdup(buffer);
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader == -1 || reader == 0)
		return (free(str), NULL);
	while (reader != 0)
	{
		str = free_stock(str, buffer);
		if (check_if_nline(buffer) == -1)
			return (for_next_line(buffer), str);
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	return (str);
}

int	main(void)
{
	char	*file = "text.txt";
	int fd = open(file, O_RDWR);
	char *line;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		free (line);
	}
	close (fd);
}
