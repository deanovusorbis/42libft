/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:23:19 by natlas            #+#    #+#             */
/*   Updated: 2024/11/17 14:24:58 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dc;
	size_t	sc;
	size_t	i;
	size_t	j;

	dc = ft_strlen(dst);
	sc = ft_strlen(src);
	i = dc;
	j = 0;
	if (dstsize == 0)
		return (sc);
	if (dstsize <= dc)
		return (dstsize + sc);
	while (i < dstsize - 1 && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dc + sc);
}
