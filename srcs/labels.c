/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:23 by meyami            #+#    #+#             */
/*   Updated: 2018/07/26 20:38:26 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	labels_free(t_label *labels)
{
	if (!labels)
		return ;
	labels_free(labels->next);
	free(labels);
}

int		labels_add(t_data *data, t_line *line)
{
	t_label *new;
	t_label *ptr;

	if (!(new = ft_memalloc(sizeof(t_label))))
	{
		ft_printf("Error in saving the line %d label\n", line->line_nb);
		return (0);
	}
	new->name = line->label;
	new->destination = line;
	new->next = 0;
	if (!data->labels)
		data->labels = new;
	else
	{
		ptr = data->labels;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (1);
}

int		labels_find(t_data *data, int line_nb, char *to_find)
{
	t_label *label;

	label = data->labels;
	while (label)
	{
		if (ft_strequ(label->name, to_find))
			return (label->destination->index);
		label = label->next;
	}
	ft_printf("Error: label not found in line %d\n", line_nb);
	return (-1);
}

char	*labels_modify_parameter(int direct, t_line *line, int destination)
{
	char *s;
	char *s_dir;

	s = ft_itoa(destination < line->index
			? MEM_SIZE - (line->index - destination)
			: destination - line->index);
	if (direct)
	{
		s_dir = ft_strjoin("%", s);
		free(s);
		return (s_dir);
	}
	return (s);
}

int		labels_replace(t_data *data)
{
	t_line	*line;
	int		target;
	int		direct;
	int		i;

	line = data->lines;
	while (line)
	{
		i = -1;
		while (++i < line->nb_params)
		{
			direct = line->params[i][1] == LABEL_CHAR;
			if (line->params[i][0] == LABEL_CHAR || direct)
			{
				if ((target = labels_find(data, line->line_nb,
											line->params[i] + 1 + direct)) == -1)
					return (0);
				free(line->params[i]);
				line->params[i] = labels_modify_parameter(direct, line, target);
			}
		}
		line = line->next;
	}
	return (1);
}
