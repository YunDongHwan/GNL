/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:28:28 by doyun             #+#    #+#             */
/*   Updated: 2021/02/18 23:50:29 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define READMAX 32
# define NONEWLINE -2

int		get_next_line(int fd, char **line);
int		get_next_line_utils.c

# endif
