/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:26:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/24 23:46:40 by doyun            ###   ########.fr       */
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

#include <stdio.h>
int					get_next_line(int fd, char **line)
{
	int				check_read;
	char			buff[BUFFER_SIZE + 1];
	int				chk_nl;
	static char		*stc_line[4096];
	char			*temp;

//		printf("-----start gnl-----\n");
//	printf("start stc : %s\n", stc_line[fd]);/////////////
	if (fd < 0 || !line)
	{
		printf("-----end gnl 1-----\n");
		return (-1);
	}
	check_read = read(fd, buff, BUFFER_SIZE);
//printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	printf("gnl read : %d\n", check_read);//////////////
	while (check_read > 0)
	{
		printf("-----------start while-------------------------\n");
	   	
		buff[check_read] = '\0';
		temp = str_join(stc_line[fd], buff);
//	printf("join in temp : %s\n", temp);/////////////
		chk_nl = check_newline(temp);
//	printf("newline index : %d\n", chk_nl);/////////////
		if (chk_nl != NONEWLINE && chk_nl != -1)
		{
			line = sub_str(temp, 0, chk_nl);
//			printf("put line : %s\n", *line);
			stc_line[fd] = sub_str(temp, chk_nl + 1, 
					str_len(temp) - chk_nl - 1);
//		printf("nl next stc : %s\n", stc_line[fd]);/////////////
			printf("-----end gnl 2-----\n");
			free(temp);
			temp = 0;
			return (1);
		}
		stc_line[fd] = temp;
		free(temp);
		temp = 0;
//		printf("stc : %s\n", stc_line[fd]);/////////////
//		printf("temp : %s\n", temp);//////////////
		check_read = read(fd, buff, BUFFER_SIZE);		
	}
	temp = stc_line[fd];
	if (check_read == -1)
	{
		free(temp);
		temp = 0;
		printf("-----end gnl 3-----");
		stc_line[fd] = 0;
		return (-1);	
	}
	if (check_read == 0)
	{
//	printf("1\n");
		if (*temp)
		{
//		printf("read 0 stc : %s\n", stc_line[fd]);/////////////
			chk_nl = check_newline(temp);
//	printf("stc chk_nl : %d\n", chk_nl);/////////////
			line = sub_str(temp, 0, chk_nl);		
			if (!line)
			{
		printf("-----end gnl 4-----");
				return (-1);
			}
			if ((line + chk_nl) != '\0')
			{
				stc_line[fd] = sub_str(temp, chk_nl + 1, 
					str_len(temp) - chk_nl - 1);
				free(temp);
				temp = 0;
				return (1);
			}
			free(temp);
			temp = 0;
			return (0);
		}

	printf("222\n"); return (0);
	}
	temp = 0;
	*line = str_dup(""); 
		printf("-----end gnl 6-----\n");
	return (0);
}
