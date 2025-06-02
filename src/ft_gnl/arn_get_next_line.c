/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arn_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:41:50 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/13 10:52:23 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_join(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_arn_strdup("");
		char_temp = backup;
		backup = ft_arn_strjoin(char_temp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_arn_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		return (NULL);
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*arn_get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_arnalloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_and_join(fd, buf, backup);
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
