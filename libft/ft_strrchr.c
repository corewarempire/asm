/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:08:35 by meyami            #+#    #+#             */
/*   Updated: 2017/11/10 12:08:38 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = c;
	if (c != 0)
	{
		i = ft_strlen(s) - 1;
		while (i >= 0)
		{
			if (s[i] == c)
				return ((char *)(s + i));
			i--;
		}
		return (0);
	}
	else
		return ((char *)(s + ft_strlen(s)));
}
