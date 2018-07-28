/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:40:54 by meyami            #+#    #+#             */
/*   Updated: 2018/03/22 15:40:56 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	type_p(t_env *e)
{
	unsigned long int	n;
	char				*s;
	int					len;
	int					padding;

	n = va_arg(e->args, unsigned long int);
	s = itoa_long_base(e, n, 16, "0123456789abcdef");
	len = ft_strlen(s);
	padding = e->width > len ? e->width - len - 2 : 0;
	buffer_fill_char(e, ' ', e->left_align ? 0 : padding);
	buffer_fill_string(e, "0x", 2);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	free(s);
}

void	type_percent(t_env *e)
{
	int padding;

	padding = e->width > 1 ? e->width - 1 : 0;
	if (!e->left_align)
	{
		buffer_fill_char(e, '0', e->padding_0 && !e->pre_space ? padding : 0);
		buffer_fill_char(e, ' ', !e->padding_0 ? padding : 0);
	}
	buffer_fill_char(e, '%', 1);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}
