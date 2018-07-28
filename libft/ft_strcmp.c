/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:12:28 by meyami            #+#    #+#             */
/*   Updated: 2017/11/09 13:12:29 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*chars1;
	unsigned char	*chars2;

	i = 0;
	chars1 = (unsigned char *)s1;
	chars2 = (unsigned char *)s2;
	while (chars1[i] || chars2[i])
	{
		if (chars1[i] != chars2[i])
		{
			return (chars1[i] - chars2[i]);
		}
		i++;
	}
	return (chars1[i] - chars2[i]);
}
