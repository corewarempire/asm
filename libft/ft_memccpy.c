/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:51:27 by meyami            #+#    #+#             */
/*   Updated: 2017/11/11 11:51:28 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_chars;
	unsigned char	*dst_chars;
	unsigned char	ch;
	size_t			i;

	src_chars = (unsigned char *)src;
	dst_chars = (unsigned char *)dst;
	ch = (unsigned char)c;
	i = 0;
	while (i < n && src_chars[i] != ch)
	{
		dst_chars[i] = src_chars[i];
		i++;
	}
	if (i != n && src_chars[i] == ch)
	{
		dst_chars[i] = src_chars[i];
		return ((void *)dst_chars + i + 1);
	}
	else
		return (0);
}
