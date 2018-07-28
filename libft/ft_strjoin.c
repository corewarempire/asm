/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:21:31 by meyami            #+#    #+#             */
/*   Updated: 2017/11/13 16:21:33 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (len_1 + len_2) + 1)))
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcpy(ptr + len_1, s2);
	return (ptr);
}
