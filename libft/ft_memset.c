/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:15:32 by meyami            #+#    #+#             */
/*   Updated: 2017/11/10 19:15:34 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned char	ch;

	ptr = (char *)b;
	i = 0;
	ch = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = ch;
		i++;
	}
	return (b);
}
