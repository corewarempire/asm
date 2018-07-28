/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:54:50 by meyami            #+#    #+#             */
/*   Updated: 2017/11/11 13:54:52 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chars1;
	unsigned char	*chars2;
	size_t			i;

	chars1 = (unsigned char *)s1;
	chars2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (chars1[i] != chars2[i])
			return ((int)chars1[i] - chars2[i]);
		i++;
	}
	return (0);
}
