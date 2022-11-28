/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:20:46 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/16 17:36:00 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_move_line(char *left)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!left)
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
		return (ft_free(left));
	str = ft_calloc(strlen_gnl(left) - i + 1, sizeof(char));
	if (!str)
		return (ft_free(left));
	i += 1;
	while (left[i])
		str[j++] = left[i++];
	ft_free(left);
	return (str);
}

static char	*ft_get_line(char *left)
{
	char	*lines;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!left)
		return (NULL);
	while (left[i++] != '\n' && left[i] != '\0')
		continue ;
	lines = ft_calloc((i + 1), sizeof(char));
	if (!lines)
		return (NULL);
	while (i-- > 0)
	{
		lines[j] = left[j];
		j++;
	}
	return (lines);
}

static char	*ft_read(int fd, char *left)
{
	int		open_rtn;
	char	*buffer;

	open_rtn = 69;
	while (open_rtn != 0 && !ft_strchr(left, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (ft_free(left));
		open_rtn = read(fd, buffer, BUFFER_SIZE);
		if (open_rtn == -1)
			return (ft_free(left), ft_free(buffer), NULL);
		left = ft_strjoin_gnl(left, buffer);
		if (!left)
			return (ft_free(buffer), NULL);
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!left[fd])
		left[fd] = ft_calloc(1, sizeof(char));
	if (!left[fd])
		return (NULL);
	left[fd] = ft_read(fd, left[fd]);
	line = ft_get_line(left[fd]);
	if (!line)
	{
		left[fd] = ft_free(left[fd]);
		return (NULL);
	}
	left[fd] = ft_move_line(left[fd]);
	return (line);
}
