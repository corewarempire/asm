/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:56:06 by meyami            #+#    #+#             */
/*   Updated: 2017/11/10 12:56:07 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	if ((needle_len = ft_strlen(needle)) == 0)
		return ((char *)haystack);
	while (haystack[i] && i + needle_len <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strnequ(haystack + i, needle, needle_len))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
