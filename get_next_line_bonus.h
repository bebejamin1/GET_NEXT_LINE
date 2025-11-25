/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:01 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/25 10:22:22 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef NB_OF_FD
#  define NB_OF_FD 1023
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

size_t	ft_str_length(char *s);
char	*error_str_line(char *s1, char *s2);
char	*ft_str_line(char *s1, char *s2);
char	*ft_str_duplicate(char *source);
char	*for_next_buffer(char *check);
int		check_if_n_inline(char *check);
char	*free_stock(char *line, char *buffer);
char	*get_next_line(int fd);

#endif