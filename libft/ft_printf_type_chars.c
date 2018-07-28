/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:40:39 by meyami            #+#    #+#             */
/*   Updated: 2018/03/22 15:41:29 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	type_c(t_env *e)
{
	char	c;
	int		padding;

	if (!e->shift)
	{
		e->types['C'](e);
		return ;
	}
	c = (char)va_arg(e->args, int);
	padding = e->width > 1 ? e->width - 1 : 0;
	buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
	buffer_fill_char(e, c, 1);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}

void	type_lc(t_env *e)
{
	int c;
	int padding;

	c = va_arg(e->args, int);
	if (c < 0 || (c > 127 && MB_CUR_MAX <= 1) || c > UTF_MAX
			|| (c >= 0xD800 && c <= 0xDFFF))
	{
		e->err = 1;
		return ;
	}
	padding = e->width > 1 ?
			e->width - 1 - (c > 127) - (c > 2047) - (c > 65535) : 0;
	buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
	buffer_fill_utf_char(e, c);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
}

void	type_s(t_env *e)
{
	char	*s;
	int		padding;
	int		len;
	int		to_free;

	if (!e->shift)
	{
		e->types['S'](e);
		return ;
	}
	to_free = 0;
	s = va_arg(e->args, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		to_free++;
	}
	len = ft_strlen(s);
	len = e->has_precision && len > e->precision ? e->precision : len;
	padding = e->width > len ? e->width - len : 0;
	buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
	buffer_fill_string(e, s, len);
	buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	if (to_free)
		free(s);
}

void	type_ls(t_env *e)
{
	int *str;
	int padding;
	int len;

	str = va_arg(e->args, int *);
	len = ft_wstrlen(e, str);
	if (len == -2)
	{
		len = e->has_precision && e->precision < 6 ? e->precision : 6;
		padding = e->width > len ? e->width - len : 0;
		buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
		buffer_fill_utf_string(e, L"(null)", len);
		buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	}
	else if (len == -1)
		e->err = 1;
	else
	{
		padding = e->width > len ? e->width - len : 0;
		buffer_fill_char(e, ' ', !e->left_align ? padding : 0);
		buffer_fill_utf_string(e, str, len);
		buffer_fill_char(e, ' ', e->left_align ? padding : 0);
	}
}
