/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:28:39 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/31 22:22:47 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		reader_header(t_data *data, int fd, char *line)
{
	while (!(data->name && data->comment))
	{
		if (get_next_line(fd, &line) <= 0 || !reader_check_header(data, line, fd))
		{
			ft_printf("Header error: line %d, (%s)\n", data->line_nb, line);
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
		data->line_nb++;
	}
	return (1);
}

int		reader_parser(t_data *data, int fd, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line = parser_check_syntax(line, data)))
		{
			ft_printf("Syntax error: line %d, (%s)\n", data->line_nb, line);
			ft_strdel(&line);
			return (0);
		}
		//ft_strdel(&line);
		data->line_nb++;
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
	printf("name : %s\n", data->name);
	printf("comment : %s\n\n", data->comment);
	while (data->lines)
	{
		printf("line_nb   : %d\n", data->lines->line_nb);
		printf("command   : %d\n", data->lines->command);
		printf("nb_params : %d\n", data->lines->nb_params);
		printf("params    : [%s] [%s] [%s]\n\n",
		data->lines->params[0], data->lines->params[1], data->lines->params[2]);
		data->lines = data->lines->next;
	}
	while (data->labels)
	{
		printf("%s\n", data->labels->name);
		data->labels = data->labels->next;
	}
	return (1);
}
