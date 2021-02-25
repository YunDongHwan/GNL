/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:26:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/26 03:18:35 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					find_nl(char *str, char c)
{
	int idx;

	idx = 0;
	if (!str)
		return (-1); //stc_line과 buff를 join한 temp가 할당이 안된상태로 넘어왔을 때
	while (str[idx] != c)//개행찾을때까지 돌림 
	{
		if (str[idx] == '\0')//개행이 없고 널로 끝나면
			return (0);
		idx++;
	}
	return (idx);//개행도 널도 없다면
}

void				stc_free(char *stc_line, t_gnl *gnl)
{
	if (*stc_line)//스태틱변수에 널 제외 값이 있다면
	{
		gnl->temp = stc_line; // temp에 스태틱라인 주소를 주어 
		free(gnl->temp); //free하고
		stc_line = 0; //stc_line의 댕글링 포인터 방지한다.
	}
}

int					get_next_line(int fd, char **line)
{
	printf("1\n");
	t_gnl			*gnl;
	static char		**stc_line;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	gnl = (t_gnl *)malloc(sizeof(t_gnl));
	gnl->c = '\n';//없애고 find_nl의 매개변수 대신 개행 직접 적어줘도 됨
	gnl->buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	printf("2\n");
	if (!gnl->buff)//버퍼 할당 실패시
	{
		stc_free(stc_line[fd], gnl);
		return (-1);
	}	
	gnl->rdlen = read(fd, gnl->buff, BUFFER_SIZE);
	gnl->buff[gnl->rdlen] = '\0';
	printf("3\n");
	while (gnl->rdlen > 0)	//읽었다면
	{
		printf("3-1\n");
		gnl->temp = str_join(stc_line[fd], gnl->buff);//저장해둔 static과 읽은 buffjoin
		gnl->nlidx = find_nl(gnl->temp, gnl->c);//temp에서 개행 찾기
		printf("3-2\n");
		if (gnl->nlidx  >  0) // 개행이 있다면
		{
			*line = sub_str(gnl->temp, 0, gnl->nlidx);
			stc_line[fd] = str_dup(&(gnl->temp[gnl->nlidx + 1]));
			free(gnl->temp);
			return (1);
		}
		printf("3-3\n");
		if (gnl->nlidx == 0)//널을 만나면 line에 temp 다 넣어주고 끝
		{
			*line = str_dup(gnl->temp);
			free(gnl->temp);
			stc_line[fd] = 0;			
			free(gnl->buff);
			free(gnl);
			return (0);
		}
		printf("3-4\n");
		if (gnl->nlidx == -1)//temp에 동적할당 실패시
		{
			if (*stc_line[fd])//static line에 문자열이 있다면
			{
				gnl->temp = stc_line[fd];
				free(gnl->temp);
				stc_line[fd] = 0;//댕글링 방지
			}			
			free(gnl->buff);
			free(gnl);
			return (-1);
		}
		gnl->rdlen = read(fd, gnl->buff, BUFFER_SIZE);
	}
	printf("4\n");
	if (gnl->rdlen == 0) //읽을게 없을때
	{
		if (stc_line[fd] == NULL)//스태틱에도 없을때
		{
			free(gnl->buff);
			free(gnl);
			return (0);//0반환
		}
		gnl->temp = stc_line[fd];//읽을게 없으나 스태틱에 남아있다면 temp에 주고
		gnl->nlidx = find_nl(gnl->temp, gnl->c);//temp에서 개행 찾기
		if (gnl->nlidx  >  0) // 개행이 있다면
		{
			*line = sub_str(gnl->temp, 0, gnl->nlidx);
			stc_line[fd] = str_dup(&(gnl->temp[gnl->nlidx + 1]));
			free(gnl->temp);
			return (1);
		}
		if (gnl->nlidx == 0)//널을 만나면 line에 temp 다 넣어주고 끝
		{
			*line = str_dup(gnl->temp);
			free(gnl->temp);
			*stc_line[fd] = 0;
			free(gnl->buff);
			free(gnl);
			return (0);
		}
		if (gnl->nlidx == -1)//temp에 동적할당 실패시
		{
			if (stc_line[fd])//static line에 문자열이 있다면
				*stc_line[fd] = 0;//댕글링 방지			
			free(gnl->buff);
			free(gnl);
			return (-1);
		}
	}
	return (0);
}
