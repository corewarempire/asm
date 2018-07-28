/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:16:52 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:16:53 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char *format, ...)
{
	t_env	e;
	int		i;

	initializer_init(&e);
	initializer_types_init(&e);
	va_start(e.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			converter_parse(&e, format, &i);
			initializer_reset(&e);
		}
		else
		{
			buffer_fill_char(&e, format[i], format[i] != '%');
			i++;
		}
		if (e.err)
			return (-1);
	}
	buffer_print(&e);
	va_end(e.args);
	return (e.nb_printed);
}
