/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:03:42 by natlas            #+#    #+#             */
/*   Updated: 2024/11/21 16:18:59 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sn;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sn = malloc(1 * sizeof(char));
		if (!sn)
			return (NULL);
		sn[0] = '\0';
		return (sn);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sn = malloc((len + 1) * sizeof(char));
	if (!sn)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sn[i] = s[start + i];
		i++;
	}
	sn[i] = '\0';
	return (sn);
}
