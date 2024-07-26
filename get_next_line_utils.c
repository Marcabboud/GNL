/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:33:12 by mabboud           #+#    #+#             */
/*   Updated: 2024/04/24 15:00:40 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	is_charset(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	a;
	size_t	b;
	size_t	i;
	size_t	y;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	join = malloc(sizeof(char) * (a + b + 1));
	if (join == NULL)
		return (0);
	i = 0;
	while (i < a)
	{
		join[i] = s1[i];
		i++;
	}
	y = 0;
	while (y < b)
		join[i++] = s2[y++];
	join[i] = '\0';
	return (free(s1), join);
}
