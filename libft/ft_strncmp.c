/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:48:01 by meyami            #+#    #+#             */
/*   Updated: 2017/11/09 14:48:03 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uch1;
	unsigned char	*uch2;

	uch1 = (unsigned char *)s1;
	uch2 = (unsigned char *)s2;
	i = 0;
	while ((uch1[i] || uch2[i]) && i < n)
	{
		if (uch1[i] != uch2[i])
		{
			return (uch1[i] - uch2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	else
		return (uch1[i] - uch2[i]);
}
