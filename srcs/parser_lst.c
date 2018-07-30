/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:46:12 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/30 23:44:30 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

t_line	*parser_lstnew(void)
{
	t_line	*new;
	int		i;

	i = 0;
	if (!(new = (t_line *)(malloc(sizeof(t_line)))))
		return (0);
	new->index = 0;
	new->command = 0;
	new->nb_params = 0;
	bzero(new->params_type, 4);
	new->params_code_byte = 0;
	if (!(new->params = (char **)(malloc(sizeof(char *) * (4)))))
		return (0);
	while (i < 4)
		new->params[i++] = 0;
	return (new);
}

int		parser_handle_if_null(t_line *new)
{
	if (new->command == 0)
	{
		lines_free(new);
		return (1);
	}
	else
		return (0);
}

void	parser_lstaddend(t_line *new, t_data *data)
{
	t_line *start;

	start = data->lines;
	if (data->lines == 0)
	{
		data->lines = new;
		new->next = 0;
	}
	else
	{
		if (parser_handle_if_null(new))
			return ;
		while (data->lines->next)
			data->lines = data->lines->next;
		data->lines->next = new;
		new->next = 0;
		data->lines = start;
	}
}
