/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:28:39 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/29 01:42:28 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		reader_header(t_data *data, int fd, char *line, int nb_line)
{
	while (!(data->name && data->comment))
	{
		if (get_next_line(fd, &line) <= 0 || !reader_check_header(data, line))
		{
			ft_printf("Header error: line %d, (%s)\n", nb_line, line);
			free(line);
			return (0);
		}
		free(line);
		nb_line++;
	}
	return (nb_line);
}

int		reader_parser(t_data *data, int fd, char *line, int nb_line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (!parser_check_syntax(line, data))
		{
			ft_printf("Syntax error: line %d, (%s)\n", nb_line, line);
			free(line);
			return (0);
		}
		nb_line++;
		free(line);
	}
	return (nb_line);
}

int		reader_read(int fd, t_data *data)
{
	int		nb_line;
	char	*line;

	line = 0;
	nb_line = 1;
	if (!(nb_line = reader_header(data, fd, line, nb_line)))
		return (0);
	if (!(nb_line = reader_parser(data, fd, line, nb_line)))
		return (0);
	return (1);
}
