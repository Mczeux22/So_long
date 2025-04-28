/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:58 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/06 19:47:04 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*ft_memory(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tab = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!tab)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		tab[j++] = buffer[i++];
	free (buffer);
	return (tab);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*tab;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tab = ft_calloc(i + 2, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tab[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		tab[i] = '\n';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		i;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i > 0)
	{
		buffer[i] = '\0';
		res = ft_memory(res, buffer);
		if (!res)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (i == -1)
		return (free(res), NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next_line(buffer);
	return (line);
}
