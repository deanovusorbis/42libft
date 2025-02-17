/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:03:39 by natlas            #+#    #+#             */
/*   Updated: 2024/11/17 18:07:01 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_findstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	st;

	st = 0;
	while (s1[st])
	{
		i = 0;
		while (set[i] && (s1[st] != set[i]))
			i++;
		if (set[i] == '\0')
			return (st);
		st++;
	}
	return (st);
}

static size_t	ft_findend(char const *s1, char const *set)
{
	size_t	i;
	size_t	ed;

	if (!*s1)
		return (0);
	ed = ft_strlen(s1) - 1;
	while (ed > 0)
	{
		i = 0;
		while (set[i] && (s1[ed] != set[i]))
			i++;
		if (set[i] == '\0')
			return (ed);
		ed--;
	}
	return (ed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sn;
	size_t	st;
	size_t	ed;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	st = ft_findstart(s1, set);
	ed = ft_findend(s1, set);
	if (st > ed)
		return (ft_strdup(""));
	sn = malloc((ed - st + 2) * sizeof(char));
	if (!sn)
		return (NULL);
	i = 0;
	while (st <= ed)
		sn[i++] = s1[st++];
	sn[i] = '\0';
	return (sn);
}
