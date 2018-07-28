/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:34:05 by meyami            #+#    #+#             */
/*   Updated: 2017/11/11 11:34:05 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_chars;
	char	*dst_chars;
	size_t	i;

	src_chars = (char *)src;
	dst_chars = (char *)dst;
	i = 0;
	while (i < n)
	{
		dst_chars[i] = src_chars[i];
		i++;
	}
	return (dst);
}
