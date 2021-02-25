/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:28:28 by doyun             #+#    #+#             */
/*   Updated: 2021/02/26 02:09:05 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define NONEWLINE -2

typedef struct	s_gnl
{
	char		c;//개행
	int			nlidx;//개행 찾은 인덱스
	int			rdlen;//파일 읽어온 길이
	char		*buff;//파일 읽으며 저장할 변수
	char		*temp;//문자열 임시 저장 변수
}				t_gnl;

int		get_next_line(int fd, char **line);
int		str_len(char *s);
char	*str_join(char *s1, char *s2);
char	*sub_str(char *s, int start, size_t len);
char	*str_dup(char *s1);

# endif
