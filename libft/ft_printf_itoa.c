/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:19:08 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:19:10 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_set_vars(long int *n, int *digits, int base)
{
	long int copy;

	copy = *n;
	*digits = 0;
	while (copy)
	{
		copy /= base;
		*digits = *digits + 1;
	}
}

static void		itoa_set_vars_unsigned(unsigned long int *n,
										int *digits, int base)
{
	unsigned long int copy;

	copy = *n;
	*digits = 0;
	while (copy)
	{
		copy /= base;
		*digits = *digits + 1;
	}
}

char			*itoa_long(t_env *e, long int n)
{
	char		*str;
	int			digits;

	if (!n && !e->precision_zero)
		return (ft_strdup("0"));
	else if (!n && e->precision_zero)
		return (ft_strdup(""));
	if (n < 0)
	{
		e->neg = 1;
		e->pre_space = 0;
		n *= -1;
	}
	itoa_set_vars(&n, &digits, 10);
	if (!(str = malloc(sizeof(char) * digits + 1)))
		ft_error(2);
	str[digits] = 0;
	digits--;
	while (digits >= 0)
	{
		str[digits] = ft_abs_value(n % (long int)10) + 48;
		n /= 10;
		digits--;
	}
	return (str);
}

char			*itoa_long_base(t_env *e, unsigned long int n,
								int base, char *symbols)
{
	char	*str;
	int		digits;

	if (!n && !e->precision_zero)
		return (ft_strdup("0"));
	else if (!n && e->precision_zero)
		return (ft_strdup(""));
	itoa_set_vars_unsigned(&n, &digits, base);
	if (!(str = malloc(sizeof(char) * digits + 1)))
		ft_error(2);
	str[digits] = 0;
	digits--;
	while (digits >= 0)
	{
		str[digits] = symbols[ft_abs_value(n % (long int)base)];
		n /= base;
		digits--;
	}
	return (str);
}
