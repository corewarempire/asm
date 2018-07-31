/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:28 by meyami            #+#    #+#             */
/*   Updated: 2018/07/30 21:51:42 by sgalasso         ###   ########.fr       */
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
	free(lines);
}

int		lines_evaluate_size(t_line *line, t_op op)
{
	int		size;
	int		direct_size;
	int		i;

	direct_size = 4 - 2 * op.direct_size;
	size = 1 + (line->params_code_byte != 0);
	i = -1;
	// printf("------------------------------------------\n");
	// printf("line:      %d\nindex:     %d\ncommand:   %s\ncode byte: %s\n\n",
	// 		line->line_nb,
	// 		line->index,
	// 		op.name,
	// 		line->params_code_byte ? "yes" : "no");
	while (++i < line->nb_params)
	{
		// printf("parameter: %s\ntype:      %s\nsize:      %d\n\n",
		// 		line->params[i],
		// 		line->params_type[i] == T_REG ? "reg" : line->params_type[i] == T_DIR ? "dir" : "ind",
		// 		(line->params_type[i] == T_REG)
		// 		+ ((line->params_type[i] == T_DIR) * direct_size)
		// 		+ ((line->params_type[i] == T_IND) * IND_SIZE));
		size += (line->params_type[i] == T_REG)
				+ ((line->params_type[i] == T_DIR) * direct_size)
				+ ((line->params_type[i] == T_IND) * IND_SIZE);
	}
	// printf("total size %d\n", size);
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
		if (!parameters_check_legal(line, op))
			return (0);
		parameters__set_code_byte(line);
		data->prog_size += lines_evaluate_size(line, op);
		// printf("prog_size is now %d\n", data->prog_size);
		line = line->next;
	}
	return (1);
}
