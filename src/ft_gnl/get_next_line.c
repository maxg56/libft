/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:11 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 15:59:36 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

static char	*nline(char *buffer)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strchr_gnl(buffer, '\n') + 1;
	if (len <= 0 || !buffer[len - 1])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(ft_strlen(buffer + len) + 1);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[len])
		str[i++] = buffer[len++];
	str[i] = '\0';
	free(buffer);
	return (str);
}

static char	*liner(char *line)
{
	int		len;
	char	*str;

	len = ft_strchr_gnl(line, '\n') + 1;
	if (len <= 0)
		len = ft_strlen(line);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, line, len + 1);
	return (str);
}

static char	*append_to_buffer(char *buffer, char *ptr)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_strjoin_gnl(buffer, ptr);
	if (!buffer)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (buffer);
}

static char	*file_read(char *buffer, int fd)
{
	char	*ptr;
	int		nb_read;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	nb_read = read(fd, ptr, BUFFER_SIZE);
	while (nb_read > 0)
	{
		ptr[nb_read] = '\0';
		buffer = append_to_buffer(buffer, ptr);
		if (!buffer || ft_strchr(buffer, '\n') >= 0)
			break ;
		nb_read = read(fd, ptr, BUFFER_SIZE);
	}
	if (nb_read == -1 || (nb_read == 0 && buffer[0] == '\0'))
		return (free(buffer), free(ptr), NULL);
	return (free(ptr), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = file_read(buffer, fd);
	if (!buffer)
		return (NULL);
	line = liner(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = nline(buffer);
	return (line);
}
