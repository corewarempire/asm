/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:38:30 by meyami            #+#    #+#             */
/*   Updated: 2018/03/21 22:20:56 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buffer_fill_char(t_env *e, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		e->buffer[e->buffer_index] = c;
		e->buffer_index++;
		i++;
		if (e->buffer_index == BUFFER_SIZE)
			buffer_print(e);
	}
}

void	buffer_fill_string(t_env *e, char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		e->buffer[e->buffer_index] = str[i];
		e->buffer_index++;
		i++;
		if (e->buffer_index == BUFFER_SIZE)
			buffer_print(e);
	}
}

void	buffer_fill_utf_char(t_env *e, int c)
{
	if (c > 65535)
	{
		buffer_fill_char(e, (char)0b11110000 | (0b111 & (c >> 18)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & (c >> 12)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & (c >> 6)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & c), 1);
	}
	else if (c > 2047)
	{
		buffer_fill_char(e, (char)0b11100000 | (0b1111 & (c >> 12)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & (c >> 6)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & c), 1);
	}
	else if (c > 127)
	{
		buffer_fill_char(e, 0b11000000 | (0b11111 & (c >> 6)), 1);
		buffer_fill_char(e, (char)0b10000000 | (0b111111 & c), 1);
	}
	else
		buffer_fill_char(e, (char)c, 1);
}

void	buffer_fill_utf_string(t_env *e, int *str, int n)
{
	int i;
	int char_len;

	i = 0;
	while (str[i] != 0 && i < n)
	{
		char_len = ft_wcharlen(str[i]);
		buffer_fill_utf_char(e, str[i]);
		i++;
		if (char_len > 1)
			n -= char_len - 1;
	}
}

void	buffer_print(t_env *e)
{
	write(1, e->buffer, e->buffer_index);
	e->nb_printed += e->buffer_index;
	e->buffer_index = 0;
}
