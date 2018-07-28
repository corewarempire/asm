/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:19 by meyami            #+#    #+#             */
/*   Updated: 2018/07/26 20:38:21 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*file_create_name(char *path)
{
	int		len;
	char	*name;
	char	*file_name;

	len = 0;
	while (path[len] != '.')
	len++;
	name = ft_strsub(path, 0, len);
	file_name = ft_strjoin(name, ".cor");
	free(name);
	return (file_name);
}

void	file_write_number(int nb, char type, int direct_size, int fd)
{
	int i;

	if (type == T_REG)
		ft_putchar_fd((char)nb, fd);
	else if (type == T_DIR || type == T_IND)
	{
		i = type == T_DIR ? direct_size : 2;
		while (i--)
		{
			ft_putchar_fd((char)nb, fd);
			nb = nb >> 8;
		}
	}
}

void	file_write_parameters(t_data *data, t_line *line, int fd)
{
	t_op	op;
	int		nb;
	int		shift;
	int		direct_size;
	int		i;

	op = data->op_tab[line->command - 1];
	direct_size = 4 - 2 * op.direct_size;
	i = -1;
	while (++i)
	{
		shift = line->params[i][0] == 'r' || line->params[i][0] == '%';
		nb = ft_atoi(line->params[i] + shift);
		file_write_number(nb, line->params_type[i], direct_size, fd);
	}
}

void	file_write_header(t_data *data, int fd)
{
	int					padding;
	long unsigned int 	buf;

	buf = COREWAR_EXEC_MAGIC;
	ft_putnchar_fd((void *)buf, 4, fd);
	padding = PROG_NAME_LENGTH - ft_strlen(data->name);
	padding = padding > 0 ? padding + (padding % 4) + sizeof(unsigned int) : 0;
	ft_putstr_fd(data->name, fd);
	while (padding)
	{
		ft_putchar_fd(0, fd);
		padding--;
	}
	buf = (long unsigned int)data->prog_size;
	ft_putnchar_fd((void *)buf, 4, fd);
	ft_putstr_fd(data->comment, fd);
	padding = COMMENT_LENGTH - ft_strlen(data->comment) - 1;
	padding = padding > 0 ? padding + padding % 4: 0;
	while (padding)
	{
		ft_putchar_fd(0, fd);
		padding--;
	}
}

int		file_write(t_data *data, int fd, char *path)
{
	char	*file_name;
	t_line	*line;

	if (!(file_name = file_create_name(path))
		|| (fd = open(file_name, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXO)) == -1)
	{
		if (file_name)
			free(file_name);
		ft_printf("error in file writing\n");
		return (0);
	}
	ft_printf("Writing output program to %s\n", file_name);
	free(file_name);
	file_write_header(data, fd);
	line = data->lines;
	while (line)
	{
		ft_putchar_fd((char)line->command, fd);
		if (line->params_code_byte)
			ft_putchar_fd(line->params_code_byte, fd);
		file_write_parameters(data, line, fd);
		line = line->next;
	}
	close(fd);
	return (1);
}
