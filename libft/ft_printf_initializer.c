/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:19:34 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:19:37 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	initializer_init(t_env *e)
{
	*e = (t_env) {
		.buffer_index = 0,
			.nb_printed = 0,
			.left_align = 0,
			.alternate_form = 0,
			.padding_0 = 0,
			.pre_space = 0,
			.plus_sign = 0,
			.width = 0,
			.precision = 0,
			.has_precision = 0,
			.precision_zero = 0,
			.length = 0,
			.shift = 32,
			.type = 0,
			.neg = 0
	};
	ft_bzero(e->buffer, BUFFER_SIZE);
}

void	initializer_types_init(t_env *e)
{
	e->types['d'] = &type_d_i;
	e->types['D'] = &type_ld;
	e->types['i'] = &type_d_i;
	e->types['s'] = &type_s;
	e->types['S'] = &type_ls;
	e->types['p'] = &type_p;
	e->types['o'] = &type_o;
	e->types['O'] = &type_lo;
	e->types['u'] = &type_u;
	e->types['U'] = &type_lu;
	e->types['x'] = &type_x;
	e->types['X'] = &type_maj_x;
	e->types['c'] = &type_c;
	e->types['C'] = &type_lc;
	e->types['%'] = &type_percent;
	e->types['b'] = &type_b;
}

void	initializer_reset(t_env *e)
{
	e->left_align = 0;
	e->alternate_form = 0;
	e->padding_0 = 0;
	e->pre_space = 0;
	e->plus_sign = 0;
	e->width = 0;
	e->precision = 0;
	e->has_precision = 0;
	e->precision_zero = 0;
	e->length = 0;
	e->shift = 32;
	e->type = 0;
	e->neg = 0;
}
