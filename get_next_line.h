/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:01 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/14 11:55:49 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif