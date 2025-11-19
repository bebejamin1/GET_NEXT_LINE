/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:55:56 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/19 15:59:05 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_countlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*error(char *s1, char *s2)
{
	char	*str;

	if (!s1 && s2)
	{
		str = ft_stringdup(s2);
		return (str);
	}
	else if (!s2 && s1)
	{
		str = ft_stringdup(s1);
		return (str);
	}
	return (NULL);
}

char	*ft_castjoin(char *s1, char *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (error(s1, s2));
	str1 = malloc(sizeof(char) * (ft_countlen(s1) + ft_countlen(s2)) + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str1[i] = s2[j];
		j++;
		i++;
	}
	while (s2[j] == '\n' && s2[j] != '\0')
		str1[i++] = s2[j++];
	return (str1[i] = '\0', str1);
}

char	*ft_stringdup(char *source)
{
	char	*dest;
	char	*src2;
	int		i;

	i = 0;
	src2 = (char *)source;
	dest = malloc(sizeof(char) * ft_countlen(source) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = src2[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
