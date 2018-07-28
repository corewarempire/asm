/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:37:44 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 21:38:03 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	format_handle(t_env *e, char c)
{
	if (c == '-')
		e->left_align = 1;
	else if (c == '+')
	{
		e->plus_sign = 1;
		e->pre_space = 0;
	}
	else if (c == ' ' && !e->plus_sign)
		e->pre_space = 1;
	else if (c == '0')
		e->padding_0 = 1;
	else if (c == '#')
		e->alternate_form = 1;
}

int			format_find(t_env *e, char format)
{
	if (ft_substr(" #-+0", format) && !e->width && !e->precision
			&& !e->length && !e->type)
	{
		format_handle(e, format);
		return (1);
	}
	else
		return (0);
}
