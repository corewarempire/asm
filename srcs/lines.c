/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:28 by meyami            #+#    #+#             */
/*   Updated: 2018/07/26 20:38:30 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lines_free(t_line *lines)
{
	if (!lines)
		return ;
	lines_free(lines->next);
	while (lines->nb_params)
	{
		free(lines->params[lines->nb_params - 1]);
		lines->nb_params--;
	}
	free(lines->params);
	free(lines->label);
	free(lines);
}

int		lines_evaluate_size(t_line *line, t_op op)
{
	int		size;
	int		direct_size;
	int		i;

	direct_size = 4 - 2 * op.direct_size;
	size = 1;
	i = -1;
	while (++i < line->nb_params)
	{
		size += (line->params_type[i] == T_REG)
				+ ((line->params_type[i] == T_DIR) * direct_size)
				+ ((line->params_type[i] == T_IND) * 2);
	}
	return (size);
}

int		lines_review(t_data *data)
{
	t_line	*line;
	int		line_nb;
	t_op	op;
	int		line_size;

	line = data->lines;
	line_nb = 1;
	while (line)
	{
		op = data->op_tab[line->command - 1];
		if (!parameters_check_legal(line, op)
			|| (line->label && !labels_add(data, line)))
			return (0);
		parameters__set_code_byte(line);
		line_size = lines_evaluate_size(line, op);
		data->prog_size += line_size;
		if (line->next)
			line->next->index = line->index + line_size;
		line = line->next;
		line_nb++;
	}
	return (1);
}
