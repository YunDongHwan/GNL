/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:28:13 by doyun             #+#    #+#             */
/*   Updated: 2021/02/23 06:01:39 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_len(char *s)
{
	int len;
	
	len = 0;
	if (!s)
		return (0);
	while(s[len])
		len++;
	return (len);
}

void		str_cpy(char *dst, const char *src)
{
	size_t	idx;

	idx = 0;
	if (!dst && !src)
		return ;
	while (src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';	
}

char	*str_join(char *s1, char *s2)
{
	unsigned char	*str_j;
	int				len;
	int				idx;
	int				len_s1;
	int				len_s2;

	if (!s1)
		return (NULL);
	len_s1 = str_len(s1);
	len_s2 = str_len(s2);
	len = len_s1 + len_s2;
	str_j = (unsigned char *)malloc(sizeof(char) * (len + 1));
	if (!str_j)
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

char				*sub_str(char *s, int start, size_t len)
{
	char	*dest;
	char	*src;
	unsigned int	idx;

	src = s;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!dest || !s)
		return (0);
	idx = 0;
	while (idx < len && src[start] && !(start > str_len(src)))
	{
		dest[idx] = src[start];
		idx++;
		start++;
	}
	dest[idx] = '\0';
	return (dest);
}

