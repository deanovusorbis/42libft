/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:02:51 by natlas            #+#    #+#             */
/*   Updated: 2024/11/23 13:40:21 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_pieces(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**pieces;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	pieces = (char **)ft_calloc(ft_count_pieces(s, c) + 1, sizeof(char *));
	if (!pieces)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < ft_count_pieces(s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		pieces[i] = ft_substr(s, start, end - start);
		if (!pieces[i])
			return (free_all(pieces));
		start = end;
	}
	return (pieces);
}
