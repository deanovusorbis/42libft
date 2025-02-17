/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:56:17 by natlas            #+#    #+#             */
/*   Updated: 2024/11/09 18:05:51 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s01;
	unsigned const char	*s02;

	s01 = (unsigned const char *)s1;
	s02 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (s01[i] != s02[i])
		{
			return ((int)(s01[i] - s02[i]));
		}
		i++;
	}
	return (0);
}
