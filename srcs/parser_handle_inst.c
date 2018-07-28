/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:53:01 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/29 01:22:14 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

int		ft_partof(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		parser_is_inst(char *inst, t_op *op_tab, t_line *new)
{
	int		j;

	j = 0;
	while (j < 16)
	{
		if (ft_strequ(inst, op_tab[j].name))
		{
			new->command = op_tab[j].op_code;
			new->nb_params = op_tab[j].nb_params;
			return (1);
		}
		j++;
	}
	return (0);
}

char	*parser_handle_inst(char *line, t_op *op_tab, t_line *new)
{
	char	*inst;
	int		temp;
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	temp = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	if (line[i] == 0)
		return (0);
	if (!(inst = ft_strsub(line, temp, i - temp)))
		return (0);
	if (parser_is_inst(inst, op_tab, new))
	{
		line += i;
		free(inst);
		return (line);
	}
	free(inst);
	return (0);
}
