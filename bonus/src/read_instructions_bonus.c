/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:02:52 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/12 23:20:05 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

char	*join(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*read_line(char *buffer)
{
	char	*line;
	size_t	len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (ft_strchr(buffer, 10))
		len++;
	if (!len)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (free(buffer), NULL);
	line[len] = '\0';
	while (len--)
		line[len] = buffer[len];
	free(buffer);
	return (line);
}

char	*save_rem(char *line)
{
	char	*reminder;
	size_t	len;

	if (!line)
		return (NULL);
	line = ft_strchr(line, '\n') + 1;
	len = ft_strlen(line);
	if (!len)
		return (NULL);
	reminder = malloc(len + 1);
	if (!reminder)
		return (free(line), NULL);
	reminder[len] = '\0';
	while (len--)
		reminder[len] = line[len];
	return (reminder);
}

void	read_at_nl(int fd, char **line)
{
	char		*buffer;
	ssize_t		ret;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(buffer), free(*line), (void)(*line = NULL));
		buffer[ret] = '\0';
		*line = join(*line, buffer);
		if (!*line)
			return (free(buffer));
		if (ft_strchr(*line, 10))
			break ;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = reminder;
	reminder = NULL;
	read_at_nl(fd, &line);
	if (ft_strchr(line, 10))
		reminder = save_rem(line);
	if (!line)
		return (NULL);
	return (read_line(line));
}
