/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:13 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/25 10:46:06 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*for_next_buffer(char *check)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check[i] != '\n' && check[i] != '\0')
		i++;
	if (check[i] == '\n')
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

int	check_if_n_inline(char *check)
{
	int	i;

	i = 0;
	while (check[i] != '\0')
	{
		if (check[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}

char	*free_stock(char *line, char *buffer)
{
	char	*stock;

	stock = NULL;
	if (!line)
		line = ft_str_duplicate("");
	stock = ft_str_duplicate(line);
	free(line);
	line = ft_str_line(stock, buffer);
	free(stock);
	return (line);
}

char	*reader_loop(ssize_t reader, int fd, char *buffer, char *line)
{
	while (reader > 0)
	{
		if (buffer[0] == '\0')
		{
			reader = read(fd, buffer, BUFFER_SIZE);
			buffer[reader] = '\0';
		}
		if (reader == 0 && buffer[0] == '\0')
			return (line);
		if (reader == -1)
			return (free(line), NULL);
		line = free_stock(line, buffer);
		if (!line || line[0] == '\0')
			return (free(line), line);
		if (check_if_n_inline(line) == -1)
			return (for_next_buffer(buffer), line);
		for_next_buffer(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[NB_OF_FD][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		reader;

	line = NULL;
	reader = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = reader_loop(reader, fd, buffer[fd], line);
	return (line);
}

// int	main(void)
// {
// 	char *line;
// 	int i = 0;
// 	//
// 	/////////// text.txt /////////////////
// 	//
// 	int		fd1 = open("text/one_line_no_nl.txt", O_RDWR);
// 	int		fd2 = open("text/41_with_nl", O_RDWR);
// 	int		fd3 = open("text/text.txt", O_RDWR);
// 	int		fd4 = open("text/text.txt", O_RDWR);
// 	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
// 	printf("NB_OF_FD : %d\n\n", NB_OF_FD);
// 	while (1)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free (line);
// 		i++;
// 	}
// 	printf("\ni : %d\n\n", i);
// 	i = 0;
// 		while (1)
// 	{
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free (line);
// 		i++;
// 	}
// 	printf("\ni : %d\n\n", i);
// 	i = 0;
// 		while (1)
// 	{
// 		line = get_next_line(fd3);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free (line);
// 		i++;
// 	}
// 	printf("\ni : %d\n\n", i);
// 		i = 0;
// 		while (1)
// 	{
// 		line = get_next_line(fd4);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free (line);
// 		i++;
// 	}
// 	printf("\ni : %d\n\n", i);
// 	close (fd1);
// 	close (fd2);
// 	close (fd3);
// 	close (fd4);
// }