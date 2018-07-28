/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:05:22 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:06:24 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(int code)
{
	if (code == 1)
		ft_putendl("an error occured");
	else if (code == 2)
	{
		ft_putendl("error");
	}
	exit(0);
}

int			ft_substr(char *haystack, char needle)
{
	const char *s;

	s = (const char *)haystack;
	return (ft_strchr(s, needle) != NULL);
}

long int	ft_abs_value(long int number)
{
	return (number < 0 ? number * -1 : number);
}

int			ft_wcharlen(int c)
{
	if (c > 65535)
		return (4);
	else if (c > 2047)
		return (3);
	else if (c > 127)
		return (2);
	else
		return (1);
}

int			ft_wstrlen(t_env *e, int *str)
{
	int i;
	int len;

	if (!str)
		return (-2);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 0 || str[i] > UTF_MAX || (str[i] > 127 && MB_CUR_MAX <= 1)
				|| (str[i] >= 0xD800 && str[i] <= 0xDFFF))
			return (-1);
		else if (e->has_precision && len + ft_wcharlen(str[i]) > e->precision)
			return (len);
		else
		{
			len += ft_wcharlen(str[i]);
			i++;
		}
	}
	return (len);
}
