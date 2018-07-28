/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:24:04 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/28 21:38:53 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

int			ft_partof(char c, char *str)
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

int		parser_is_digits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		parser_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_partof(str[i], LABEL_CHARS))
			return (0);
		i++;
	}
	return (1);
}

char	*parser_cut_line(char *line)
{
	char	*cut;
	int		i;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	if (line[i] == '#')
	{
		if (!(cut = ft_strsub(line, 0, i))) // LEAK ?
			return (0);
		return (cut);
	}
	return (line);
}

char	*parser_handle_label(char *line, t_line *new)
{
	int	i;
	int temp;

	i = 0;
	while (line[i] && line[i] == ' ' && line[i] == '\t')
		i++;
	temp = i;
	if (line[i] == ':')
		return (0);
	while (line[i] && line[i] != ':'  && line[i] != ' ' && line[i] != '\t')
	{
		if (!ft_partof(line[i++], LABEL_CHARS))
			return (0);
	}
	if (line[i] == ':')
	{
		new->label = ft_strsub(line, temp, i - temp); // LEAK ?
		line += i + 1;
		return (line);
	}
	if (line[i] == 0)
		return (0);
	return (line);
}

int		parser_is_inst(char *line, int temp, int i, t_op *op_tab, t_line *new)
{
	char	*inst;
	int		j;

	j = 0;
	inst = ft_strsub(line, temp, i - temp);
	while (j < 16)
	{
		if (ft_strequ(inst, op_tab[j].name))
		{
			new->command = op_tab[j].op_code;
			new->nb_params = op_tab[j].nb_params;
			free(inst);
			return (1);
		}
		j++;
	}
	free(inst);
	return (0);
}

char	*parser_handle_inst(char *line, t_op *op_tab, t_line *new)
{
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
	if (parser_is_inst(line, temp, i, op_tab, new))
	{
		line += i;
		return (line);
	}
	return (0);
}

char	*parser_handle_param(char *line, t_line *new, int nbp)
{
	char	*param;
	int		temp;
	int		i;

	i = 0;
	if (line[i] == 0)
		return (0);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	temp = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != ',')
		i++;
	if (!(param = ft_strsub(line, temp, i - temp))) // LEAK ?
		return (0);
	if ((param[0] == '%' && parser_is_digits(param + 1))
	|| (param[0] == '%' && param[1] == ':' && parser_is_label(param + 2))
	|| (param[0] == ':' && parser_is_label(param + 1))
	|| (parser_is_digits(param + 1)))
	{
		new->params[nbp] = param;
		line += i;
		return (line);
	}
	return (0);
}

t_line	*parser_lstnew()
{
	t_line *new;
	int		i;

	i = 0;
	if (!(new = (t_line *)(malloc(sizeof(t_line)))))
		return (0);
	new->index = 0;
	new->label = 0;
	new->command = 0;
	new->nb_params = 0;
	if (!(new->params = (char **)(malloc(sizeof(char *) * (4)))))
		return (0);
	while (i < 4)
		new->params[i++] = 0;
	return (new);
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
		while (data->lines->next)
			data->lines = data->lines->next;
		data->lines->next = new;
		new->next = 0;
		data->lines = start;
	}
}

int		parser_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	*parser_check_syntax(char *line, t_data *data)
{
	char	*temp;
	t_line	*new;
	int		nbp;

	nbp = 0;
	temp = line;
	if (!(line = parser_cut_line(line)))
		return (0);
	if (parser_is_empty(line))
		return (temp);
	if (!(new = parser_lstnew()))
		return (0);


	// Traitement du contenu
	if (!(line = parser_handle_label(line, new)))
		return (0);
	if (!parser_is_empty(line))
	{
		if (!(line = parser_handle_inst(line, data->op_tab, new)))
			return (0);
		if (!(line = parser_handle_param(line, new, nbp++)))
			return (0);
		while (nbp < new->nb_params && *line)
		{
			while (*line && (*line == ' ' || *line == '\t'))
				line++;
			if (*line != ',')
				return (0);
			line++;
			while (*line && (*line == ' ' || *line == '\t'))
				line++;
			if (!(line = parser_handle_param(line, new, nbp++)))
				return (0);
		}
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line != 0 || nbp != new->nb_params)
		{
			printf("line : %s\n", line);
			printf("nbp : %d | sur : %d\n", nbp, new->nb_params);
			return (0);
		}
	}
	parser_lstaddend(new, data);
	//_________________________


	return (temp);
}
