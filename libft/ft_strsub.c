/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:58:01 by meyami            #+#    #+#             */
/*   Updated: 2017/11/13 15:58:02 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	int		valid;
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	valid = (len <= str_len);
	if (!valid)
		return (0);
	else
	{
		if (!(ptr = malloc(sizeof(char) * len + 1)))
			return (0);
		i = 0;
		while (i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = 0;
		return (ptr);
	}
}
