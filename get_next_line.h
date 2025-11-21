/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:01 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/11/21 14:57:14 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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

size_t	ft_str_length(char *s); // taille pour malloc
char	*error_str_line(char *s1, char *s2); // erreur str line
char	*ft_str_line(char *s1, char *s2); // ecrire la ligne a partir du buffer
char	*ft_str_duplicate(char *source); // malloc facilement
char	*for_next_buffer(char *check); // recopie pour la prochaine utilisation
int		check_if_n_inline(char *check); // strchr
char	*free_stock(char *line, char *buffer); // freeeeeeeee
char	*get_next_line(int fd); // fonction principale

#endif