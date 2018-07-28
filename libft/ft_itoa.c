/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:26:18 by meyami            #+#    #+#             */
/*   Updated: 2017/11/14 18:26:19 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	set_vars(int *neg, int *n, long int *copy, int *digits)
{
	if (*n == -2147483648)
		return (1);
	else
	{
		*digits = 0;
		if (*n < 0)
		{
			*neg = 1;
			*n = *n * -1;
		}
		else
			*neg = 0;
		while (*copy)
		{
			*copy /= 10;
			*digits = *digits + 1;
		}
		return (0);
	}
}

char		*ft_itoa(int n)
{
	char		*str;
	int			digits;
	long int	copy;
	int			neg;

	if (!(copy = n))
		return (ft_strdup("0"));
	else if (set_vars(&neg, &n, &copy, &digits))
		return (ft_strdup("-2147483648"));
	if (!(str = malloc(sizeof(char) * digits + neg + 1)))
		return (0);
	str[digits + neg] = 0;
	digits = digits + neg - 1;
	while (digits - neg >= 0)
	{
		str[digits] = n % 10 + 48;
		n /= 10;
		digits--;
	}
	str[0] = neg ? '-' : str[0];
	return (str);
}
