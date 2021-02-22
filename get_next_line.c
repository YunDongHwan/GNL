/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:26:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/23 06:33:19 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					check_newline(char *str)
{
	int				idx;

	idx = 0;
	if (!str)
		return (-1);
	while (str[idx])
	{
		if (str[idx] == '\n' || str[idx] == '\0')
			return (idx);
		idx++;
	}
	return (NONEWLINE);
}
/*
int					put_newline(char **line, char *str, int len)
{
	int				idx;

	idx = 0;
	if (!line || !str)
		return (-1);
	while (str[idx] != '\n' || str[idx] == '\0')
	{
		*line = str;
		idx++;
	}
	if (str[idx] == '\0')
		return (0);
	else
		return (idx);
}

int					put_static_line(char *stc, char *temp, int new_next)
{
	int				idx;

	idx = 0;
	if (!stc || !temp)
		return (-1);
	while (temp[new_next] != '\n' || temp[new_next] != '\0')
	{
		*stc++ = temp[new_next];
		new_next++;
	}
	if (temp[new_next] == '\0')
		return (-3);
	else
		return (new_next);
}
*/
#include <stdio.h>
int					get_next_line(int fd, char **line)
{
	int				check_read;
	char			buff[BUFFER_SIZE + 1];
	int				chk_nl;
	static char		*stc_line[4096];
	char			*temp;

	if (fd < 0 || !line)
		return (-1);
	check_read = read(fd, buff, BUFFER_SIZE);
	printf("%d", fd);
	while (check_read > 0)
	{
		buff[check_read] = '\0';
		if (*temp)
			free(temp);
		temp = str_join(stc_line[fd], buff);		
		chk_nl = check_newline(temp);
		if (chk_nl != NONEWLINE && chk_nl != -1)
		{
			*line = sub_str(temp, 0, chk_nl);
			stc_line[fd] = sub_str(temp, chk_nl + 1, 
					str_len(temp) - chk_nl - 1);
			return (1);
		}
		stc_line[fd] = temp;
		check_read = read(fd, buff, BUFFER_SIZE);		
	}
	if (check_read == -1)
	{
		free(stc_line[fd]);
		return (-1);	
	}
	if (check_read == 0)
	{
		if (*stc_line[fd])
		{
			chk_nl = check_newline(stc_line[fd]);
			*line = sub_str(stc_line[fd], 0, chk_nl);		
			if (!(*line))
				return (-1);
		}
		return (0);
	}
	return (-1);	
}
