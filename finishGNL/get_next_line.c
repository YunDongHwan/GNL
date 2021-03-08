/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:48:00 by doyun             #+#    #+#             */
/*   Updated: 2021/03/08 23:09:05 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					find_nl(char *str)
{
	int 			idx;

	idx = 0;
	if (!str)
		return (-1);
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
		if (str[idx] == '\0')
			return (-2);
	}
	return (-1);
}

void				put_line(char **line, char **stc_line, int nlidx)
{
	char			*temp;	

	temp = *stc_line;
	*line = sub_str(temp, 0, nlidx);	
	if (temp[nlidx + 1])
		*stc_line = str_dup(&temp[nlidx + 1]);
	else		
		*stc_line = 0;
	free(temp);
}

int					not_read(int rdlen, char **line, char **stc_line)
{
	int				nlidx;
	char			*temp;

	if (rdlen < 0)
		return (-1);
	nlidx = find_nl(*stc_line);
	if (nlidx >= 0)
	{
		put_line((&(*line)), &(*stc_line), nlidx);
		return (1);
	}
	else if (*stc_line)
	{
		*line = str_dup(*stc_line);
		temp = *stc_line;
		free(temp);
		*stc_line = 0;
		return (0);
	}
	*line = str_dup("");
	return (0);
}

int				can_read(int rdlen, char **line, char **stc_line, char *buff, int fd)
{
	int			nlidx;
	char		*temp;

	while (rdlen > 0)
	{
		buff[rdlen] = '\0';
		temp = *stc_line;
		*stc_line = str_join(temp, buff);
		free(temp);
		nlidx = find_nl(*stc_line);
		if (nlidx >= 0)
		{
			put_line(&(*line), &(*stc_line), nlidx);
			return (1);
		}
		else if (nlidx == -2)
		{
			*line = str_dup(*stc_line);
			*stc_line = 0;
			return (0);
		}
		rdlen = read(fd, buff, BUFFER_SIZE);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *stc_line[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rdlen;
	int			rdchk;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rdlen = read(fd, buff, BUFFER_SIZE);
	rdchk = can_read(rdlen, &(*line), &(stc_line[fd]), buff, fd);
	if (rdchk)
		return (1);
	rdchk = not_read(rdlen, &(*line), &(stc_line[fd]));
	return (rdchk);
}
