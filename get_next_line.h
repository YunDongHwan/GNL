/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:28:28 by doyun             #+#    #+#             */
/*   Updated: 2021/02/23 01:38:34 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# define READMAX 32
# define NONEWLINE -2

int		get_next_line(int fd, char **line);
int		str_len(char *s);
void	str_cpy(char *dst, const char *src);
char	*str_join(char *s1, char *s2);

# endif
