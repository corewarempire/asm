/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:11:18 by meyami            #+#    #+#             */
/*   Updated: 2017/11/09 17:11:19 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = s[0];
	ch = c;
	if (c != 0)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return ((char *)(s + i));
			i++;
		}
		return (0);
	}
	else
		return ((char *)(s + ft_strlen(s)));
}
