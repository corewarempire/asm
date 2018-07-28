/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:26:23 by meyami            #+#    #+#             */
/*   Updated: 2018/03/26 16:26:26 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_long(const char *str)
{
	long int				i;
	long int				sign;
	long int				nb;
	unsigned char			*s;

	i = 0;
	sign = 1;
	nb = 0;
	s = (unsigned char *)str;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			nb = nb * 10 + s[i] - 48;
		else if (!nb && s[i] == '-' && ft_isdigit(s[i + 1]))
			sign = -1;
		else if (!nb &&
				((s[i] == '+' && ft_isdigit(s[i + 1]))
					|| s[i] == ' ' || s[i] <= 13))
		{
		}
		else
			return (nb * sign);
		i++;
	}
	return (nb * sign);
}
