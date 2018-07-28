/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:10:33 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:21:25 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	converter_parse(t_env *e, char *format, int *index)
{
	int	i;

	i = *index + 1;
	while (!type_find(format[i]))
	{
		if (format_find(e, format[i]) || width_find(e, format + i)
			|| precision_find(e, format + i) || length_find(e, format + i))
			i++;
		else if (format[i] == '%')
			break ;
		else
			e->err = 1;
	}
	if (e->err)
		return ;
	converter_convert(e, format + i);
	i++;
	*index = i;
}

void	converter_convert(t_env *e, char *type)
{
	int	key;

	key = (int)*type;
	e->padding_0 = e->has_precision && ft_substr("dDixXuUoO", (char)key) ?
		0 : e->padding_0;
	e->types[key](e);
	e->type = 1;
}
