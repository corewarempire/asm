/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:44 by meyami            #+#    #+#             */
/*   Updated: 2018/07/26 20:38:46 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parameters_set_types(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->nb_params)
	{
		if (line->params[i][0] == 'r')
			line->params_type[i] = (T_REG);
		else if (line->params[i][0] == '%')
			line->params_type[i] = (T_DIR);
		else
			line->params_type[i] = (T_IND);
	}
}

int		parameters_check_legal(t_line *line, t_op op)
{
	int		i;

	parameters_set_types(line);
	i = -1;
	while (++i < op.nb_params)
	{
		if (!(op.argv[i] & line->params_type[i]))
		{
			ft_printf("Error in types of parameters line %d\n", line->line_nb);
			return (0);
		}
	}
	return (1);
}

char	parameters_encode(char type, int shift)
{
	type = type / 2 + (type > 0);
	return (type << shift);
}

void	parameters__set_code_byte(t_line *line)
{
	if (line->command == 1 || line->command == 9
		|| line->command == 12 || line->command == 15)
		return ;
	line->params_code_byte += parameters_encode(line->params_type[0], 6)
							+ parameters_encode(line->params_type[1], 4)
							+ parameters_encode(line->params_type[2], 2);
}
