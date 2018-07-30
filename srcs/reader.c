/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:28:39 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/30 20:46:55 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		reader_header(t_data *data, int fd, char *line)
{
	while (!(data->name && data->comment))
	{
		if (get_next_line(fd, &line) <= 0 || !reader_check_header(data, line))
		{
			ft_printf("Header error: line %d, (%s)\n", data->line_nb, line);
			free(line);
			return (0);
		}
		free(line);
		data->line_nb++;
	}
	return (1);
}

int		reader_parser(t_data *data, int fd, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line = parser_check_syntax(line, data, fd)))
		{
			ft_printf("Syntax error: line %d, (%s)\n", data->line_nb, line);
			free(line);
			return (0);
		}
		data->line_nb++;
		free(line);
	}
	return (1);
}

int		reader_read(int fd, t_data *data)
{
	char	*line;

	line = 0;
	data->line_nb = 1;
	if (!reader_header(data, fd, line))
		return (0);
	if (!reader_parser(data, fd, line))
		return (0);
	return (1);
}
