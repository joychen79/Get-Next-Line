/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:34:08 by jingchen          #+#    #+#             */
/*   Updated: 2023/02/28 20:11:23 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_newbuffer(char *buffer)
{
	int		i;
	int		bufferlen;

	i = 0;
	if (!buffer)
		return (NULL);
	bufferlen = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	buffer = ft_memmove(buffer, (buffer + i + 1), bufferlen - i + 2);
	buffer[ft_strlen(buffer)] = '\0';
	return (buffer);
}

static char	*read_line(int fd, char *buffer)
{
	char		*temp;
	int			readbyts;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	readbyts = 1;
	while (readbyts > 0 && !ft_strchr(buffer, '\n'))
	{
		readbyts = read(fd, temp, BUFFER_SIZE);
		if (readbyts <= 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[readbyts] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

/*char	*get_newline(char *buffer)
{
	char	*sub;
	int		i;
	int		j;

	if (!buffer)
		return (0);
	i = 0;
	//len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
			i++;
	sub = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!sub)
		return (0);
	i = i+1;
	j = 0;
	while (ft_strlen(buffer) > i)
		{
			sub[j++] = buffer[i++];
		}
	sub[j] = '\0';
	return (sub);
}*/

char	*get_newline(char *buffer)
{
	char	*newline;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
			i++;
	newline = ft_substr(buffer, 0, i + 1);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*newline;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buffer = read_line(fd, buffer);
	newline = get_newline(buffer);
	buffer = get_newbuffer(buffer);
	return (newline);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	// test reading a file
	fd = open("longlines.txt", O_RDONLY);
	// test STDIN 
	//fd = 0;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	free(line);
	printf("%s", line);
	line = get_next_line(fd);
	free(line);
	printf("%s", line);
	line = get_next_line(fd);
	free(line);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	system("leaks -q a.out");
	return (0);
}
*/