/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:40:47 by meyami            #+#    #+#             */
/*   Updated: 2018/03/22 15:40:47 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	type_d_i(t_env *e)
{
	long int	n;
	char		*s;
	int			len;
	int			padding;

	n = va_arg(e->args, long int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long(e, n);
	len = ft_strlen(s);
	padding = e->precision > len ? e->width - e->precision : e->width - len;
	padding -= (e->neg || (e->plus_sign && n >= 0));
	buffer_fill_char(e, ' ', e->pre_space && !e->neg && !e->plus_sign);
	padding -= e->pre_space && !e->neg && !e->plus_sign;
	buffer_fill_char(e, ' ', e->left_align ? 0 : padding * !e->padding_0);
	buffer_fill_char(e, '+', e->plus_sign && n >= 0);
	buffer_fill_char(e, '-', e->neg);
	buffer_fill_char(e, '0', e->left_align ? 0 : padding * e->padding_0);
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_ld(t_env *e)
{
	e->shift = 0;
	e->types['d'](e);
}

void	type_u(t_env *e)
{
	long unsigned int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, long unsigned int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long_base(e, n, 10, "0123456789");
	len = ft_strlen(s);
	e->precision = e->precision < len ? len : e->precision;
	padding = e->width > e->precision ? e->width - e->precision : 0;
	buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_lu(t_env *e)
{
	e->shift = 0;
	e->types['u'](e);
}
