/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:13 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/17 17:51:13 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	reader;
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;

	reader = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			printf("1");
		printf("%c", buffer[i]);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	*file = "text.txt";
	int fd = open(file, O_RDWR);
	
	get_next_line(fd);
}
