/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:22:24 by doyun             #+#    #+#             */
/*   Updated: 2021/03/09 03:28:07 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define BUFFER_SIZE 4096
# endif

int		get_next_line(int fd, char **line);
int		str_len(char *s);
char	*str_join(char *s1, char *s2);
char	*sub_str(char *s, int start, size_t len);
char	*str_dup(char *s1);

#endif
