/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:24:26 by meyami            #+#    #+#             */
/*   Updated: 2017/11/10 12:24:28 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int len;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	len = ft_strlen(needle);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strnequ(haystack + i, needle, len))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
