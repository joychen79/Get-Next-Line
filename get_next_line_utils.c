/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:18 by jingchen          #+#    #+#             */
/*   Updated: 2023/02/28 20:04:18 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
			s++;
	}
	if ((char) c == '\0')
		return (s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((int)start >= ft_strlen(s))
		return (0);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_memmove (sub, (s + start), len);
	sub[len] = '\0';
	return (sub);
}

void	*ft_memmove(void *dst, const void*src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			*(dest + len) = *(source + len);
		}
		return (dst);
	}
	while (len--)
		*(dest++) = *(source++);
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	aux;
	char	*a;
	size_t	i;

	aux = count * size;
	if (aux == 1 && count != 1)
		return (NULL);
	ptr = malloc(aux);
	if (!ptr)
		return (NULL);
	a = ptr;
	i = 0;
	while (i < aux)
	{
		*a++ = '\0';
		i++;
	}
	return (ptr);
}
