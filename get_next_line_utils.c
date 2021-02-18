/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun </var/mail/doyun>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:28:13 by doyun             #+#    #+#             */
/*   Updated: 2021/02/19 05:56:42 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		strlen(char *str)
{
	int len;
	
	len = 0;
	while(str[len])
		len++;		
	return (len);
}

int		check_newline(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (NONEWLINE);
}


char				*substr(char *s, unsigned int start, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	idx;

	src = (unsigned char *)s;
	if (!(dest = (unsigned char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!dest || !s)
		return (0);
	idx = 0;
	while (idx < len && src[start] && !(start > strlen((char *)src)))
	{
		dest[idx] = src[start];
		idx++;
		start++;
	}
	dest[idx] = '\0';
	return ((char *)dest);
}


