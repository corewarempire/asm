/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:28:39 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/28 21:50:56 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		reader_read(int fd, t_data *data)
{
	int		nb_line;
	char	*line;

	nb_line = 1;
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
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line = parser_check_syntax(line, data)))
		{
			ft_printf("Syntax error: line %d, (%s)\n", nb_line, line);
			free(line);
			return (0);
		}
		nb_line++;
		free(line);
	}
	 printf("\nname: %s\ncomment: %s\n\n", data->name, data->comment);
	 printf("nb_label : %d\n\n", data->nb_label);
	 while (data->lines)
	 {
	 	printf("label     : %s\n", data->lines->label);
	 	printf("op_code   : %d\n", data->lines->command);
	 	printf("nb_params : %d\n", data->lines->nb_params);
	 	printf("params    : [%s][%s][%s]\n\n", data->lines->params[0],
	 	data->lines->params[1], data->lines->params[2]);
	 	data->lines = data->lines->next;
	}
	return (1);
}
