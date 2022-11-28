/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:33:32 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/16 17:19:33 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (i < (nitems * size))
		ptr[i++] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = c;
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	strlen_gnl(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		++count;
	return (count);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;

	i = ULONG_MAX;
	j = ULONG_MAX;
	if ((strlen_gnl(s1) + strlen_gnl(s2)) == 0)
		return (ft_free(s1));
	result = ft_calloc((strlen_gnl(s1) + strlen_gnl(s2) + 1), sizeof(char));
	if (!result)
		return (free(s1), NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i + j] = s2[j];
	return (ft_free(s1), ft_free(s2), result);
}
