/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:35:59 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/16 17:03:06 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_free(void *str);

#endif