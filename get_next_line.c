/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:28:25 by mabboud           #+#    #+#             */
/*   Updated: 2024/04/24 15:04:34 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_str(char *src)
{
	char	*str;
	int		i;
	int		j;

	if (!src || !src[0])
		return (0);
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (str == NULL)
		return (0);
	j = 0;
	while (j <= i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*remove_str(char *str)
{
	char	*first;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		return (free(str), NULL);
	first = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!first)
		return (free(first), NULL);
	j = 0;
	i++;
	while (str[i])
	{
		first[j] = str[i];
		j++;
		i++;
	}
	first[j] = '\0';
	return (free(str), first);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	int			bytes;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	bytes = 1;
	while (!is_charset(str) && bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), NULL);
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(buf), NULL);
	}
	line = extract_str(str);
	str = remove_str(str);
	return (free(buf), line);
}
