/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:26:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/19 05:55:05 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*strjoin(char const *s1, char const *s2)
{
	unsigned char	*str_j;
	int				len;
	int				idx;
	int				len_s1;
	int				len_s2;

	if (!s1)
		return (NULL);
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	len = len_s1 + len_s2;
	if (!(str_j = (unsigned char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		if (idx < len_s1)
			str_j[idx++] = *s1++;
		else
			str_j[idx++] = *s2++;
	}
	str_j[idx] = '\0';
	return ((char *)str_j);
}

char				*put_newline(char *line, char *str, int len)
{
	int				idx;

	idx = 0;
	while (idx < len || str[idx] == '\n' || str[idx] == '\0')
	{
		line[idx] = str[idx];
		idx++;
	}
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
	while(check_read > 0)
	{
		buff[check_read] = '\0';
		temp = strjoin(stc_line, buff);
		chk_nl = check_newline(temp);
		if (chk_nl != NONEWLINE)		
			chk_nl = put_line(*line, temp, chk_line)
		check_read = read(fd, buff, READMAX);
	}
	if (check_read == -1)
	{
		free(buff);
		return (-1);
	}
	if (check_read == 0 || stc_line)
	{
		chk_nl = put_line(*line, temp, check_newline(stc_line);
	}

}
