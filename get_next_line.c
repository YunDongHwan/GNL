/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:26:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/23 02:04:45 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					put_newline(char **line, char *str)
{
	int				idx;

	idx = 0;
	while (str[idx] != '\n' || str[idx] == '\0')
	{
		*line[idx] = str[idx];
		idx++;
	}
	return (idx);
}

int		check_newline(char *str)
{
	int	idx;

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

int				put_static_line(char *stc, char *temp, int new_next)
{
	int	idx;

	idx = 0;
	if (!stc || !temp)
		return (-1);
	while (temp[new_next] != '\n' || temp[new_next] != '\0')
	{
		*stc++ = temp[new_next];
		new_next++;
	}
	if (temp[new_next] == '\0')
		return (0);
	else
		return (1);
}

 int					get_next_line(int fd, char **line)
{
	int				check_read;
	char			*buff;
	int				chk_nl;
	static char		*stc_line[4096];
	char			*temp;

	buff = (char *)malloc(sizeof(char) * READMAX + 1);
	if (fd < 0 || !line || !buff)
		return (-1);
	check_read = read(fd, buff, READMAX);
	while (check_read > 0)
	{
		buff[check_read] = '\0';
		temp = str_join(stc_line[fd], buff);
		chk_nl = check_newline(temp);
		if (chk_nl != NONEWLINE && chk_nl != -1)
		{
			chk_nl = put_newline(line, temp);		
			chk_nl = put_static_line(stc_line[fd], temp, chk_nl + 1);
			free(buff);
			buff = 0;
			return (chk_nl);
		}		
		str_cpy(stc_line[fd], temp);		
		check_read = read(fd, buff, READMAX);		
	}
	if (check_read == -1)
	{
		free(buff);
		return (-1);
	}
	if (check_read == 0 || *stc_line)
	{
		chk_nl = put_newline(line, temp);
		chk_nl = put_static_line(stc_line[fd], temp, chk_nl + 1);
		free(buff);
		buff = 0;
		if (chk_nl == 0)
			return (0);		
	}	
	return (1);
	
}
