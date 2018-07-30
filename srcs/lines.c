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
	printf("line %d, command is %s, direct params should be of size %d\n", line->line_nb, op.name, op.direct_size ? 2 : 4);
	while (++i < line->nb_params)
	{
		printf("parameter %s has size %d\n", line->params[i], (line->params_type[i] == T_REG)
				+ ((line->params_type[i] == T_DIR) * direct_size)
				+ ((line->params_type[i] == T_IND) * IND_SIZE));
		size += (line->params_type[i] == T_REG)
				+ ((line->params_type[i] == T_DIR) * direct_size)
				+ ((line->params_type[i] == T_IND) * IND_SIZE);
	}
	printf("size of line %d: %d\n", line->line_nb, size);
	return (size);
}

int		lines_review(t_data *data)
{
	t_line	*line;
	t_op	op;

	line = data->lines;
	while (line)
	{
		line->index = data->prog_size;
		op = data->op_tab[line->command - 1];
		if (!parameters_check_legal(line, op)
			|| (line->label && !labels_add(data, line)))
			return (0);
		parameters__set_code_byte(line);
		data->prog_size += lines_evaluate_size(line, op);
		line = line->next;
	}
	return (1);
}
