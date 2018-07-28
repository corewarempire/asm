/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:59:20 by meyami            #+#    #+#             */
/*   Updated: 2017/11/13 14:59:21 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * size + 1)))
		return (0);
	i = 0;
	while (i < size + 1)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
