/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:35:37 by meyami            #+#    #+#             */
/*   Updated: 2017/11/11 12:35:37 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_chars;
	unsigned char	*dst_chars;
	size_t			i;

	src_chars = (unsigned char *)src;
	dst_chars = (unsigned char *)dst;
	if (src < dst && len)
	{
		i = len - 1;
		while (i > 0)
		{
			dst_chars[i] = src_chars[i];
			i--;
		}
		dst_chars[i] = src_chars[i];
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		dst_chars[i] = src_chars[i];
		i++;
	}
	return ((void *)dst_chars);
}
