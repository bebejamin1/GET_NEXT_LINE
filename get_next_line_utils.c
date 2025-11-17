/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:55:56 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/17 17:54:11 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_countword(char *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_start_end_str(char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start) + 2);
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_malloc_string(char **string, char *s, char c)
{
	int	tab;
	int	end;
	int	start;

	tab = 0;
	end = 0;
	start = 0;
	while (s[end] != '\0')
	{
		while (s[start] == c)
			start++;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == '\0'))
		{
			string[tab] = ft_start_end_str(s, start, end);
			start = end + 1;
			tab++;
		}
		end++;
	}
	string[tab] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		nb;
	char	**string;

	nb = ft_countword((char *)s, c);
	string = malloc(sizeof(char *) * (nb + 1));
	if (!string)
		return (NULL);
	ft_malloc_string(string, (char *)s, c);
	return (string);
}
