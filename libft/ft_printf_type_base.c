/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:40:33 by meyami            #+#    #+#             */
/*   Updated: 2018/03/22 15:40:35 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	type_o(t_env *e)
{
	unsigned long int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, unsigned long int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long_base(e, n, 8, "012345678");
	len = ft_strlen(s);
	e->alternate_form = e->precision > len ? 0 : e->alternate_form;
	e->precision = e->precision < len ? len : e->precision;
	padding = e->width > e->precision ?
		e->width - e->precision -
		(e->alternate_form && s[0] != '0') : 0;
	buffer_fill_char(e, ' ', e->pre_space && !padding);
	buffer_fill_char(e, '0',
					e->alternate_form && len && s[0] != '0' && !padding);
	buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
	buffer_fill_char(e, '0',
					e->alternate_form && len && s[0] != '0' && padding);
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	if (!(!n && e->precision_zero && !e->alternate_form))
		buffer_fill_string(e, len ? s : "0", !len ? 1 : len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_lo(t_env *e)
{
	e->shift = 0;
	e->types['o'](e);
}

void	type_x(t_env *e)
{
	unsigned long int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, unsigned long int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long_base(e, n, 16, "0123456789abcdef");
	len = ft_strlen(s);
	e->precision = e->precision < len ? len : e->precision;
	padding = e->width > e->precision ?
		e->width - e->precision - e->alternate_form * 2 * (n != 0) : 0;
	buffer_fill_char(e, ' ', e->pre_space && !padding);
	buffer_fill_string(e, "0x",
						e->alternate_form * 2 * (n != 0 && e->padding_0));
	buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
	buffer_fill_string(e, "0x",
						e->alternate_form * 2 * (n != 0 && !e->padding_0));
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_maj_x(t_env *e)
{
	unsigned long int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, unsigned long int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long_base(e, n, 16, "0123456789ABCDEF");
	len = ft_strlen(s);
	e->precision = e->precision < len ? len : e->precision;
	padding = e->width > e->precision ?
		e->width - e->precision - e->alternate_form * 2 * (n != 0) : 0;
	buffer_fill_char(e, ' ', e->pre_space && !padding);
	buffer_fill_string(e, "0X",
						e->alternate_form * 2 * (n != 0 && e->padding_0));
	buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
	buffer_fill_string(e, "0X",
						e->alternate_form * 2 * (n != 0 && !e->padding_0));
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_b(t_env *e)
{
	unsigned long int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, unsigned long int);
	n = (n << e->shift) >> e->shift;
	s = itoa_long_base(e, n, 2, "01");
	len = ft_strlen(s);
	e->precision = e->precision < len ? len : e->precision;
	padding = e->width > e->precision ?
		e->width - e->precision - e->alternate_form * 2 * (n != 0) : 0;
	buffer_fill_char(e, ' ', e->pre_space && !padding);
	buffer_fill_string(e, "0b",
						e->alternate_form * 2 * (n != 0 && e->padding_0));
	buffer_fill_char(e, e->padding_0 ? '0' : ' ', e->left_align ? 0 : padding);
	buffer_fill_string(e, "0b",
						e->alternate_form * 2 * (n != 0 && !e->padding_0));
	buffer_fill_char(e, '0', e->precision > len ? e->precision - len : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}
