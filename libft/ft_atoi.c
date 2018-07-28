/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:35:23 by meyami            #+#    #+#             */
/*   Updated: 2017/11/13 11:35:28 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int				nb;
	unsigned char	*s;

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
