/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:01 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/19 15:57:19 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

char	*for_next_line(char *check);
int		check_if_nline(char *check);
char	*free_stock(char *str, char *buffer);
char	*get_next_line(int fd);
size_t	ft_countlen(const char *s);
char	*error(char *s1, char *s2);
char	*malloc_castjoin(char const *s1, char const *s2);
char	*ft_castjoin(char *s1, char *s2);
char	*ft_stringdup(char *source);

#endif