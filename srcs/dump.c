/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 00:52:36 by meyami            #+#    #+#             */
/*   Updated: 2018/08/01 00:52:37 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int dump_flag_management(t_data *data, int ac, char **av)
{
	if (ac == 3 && ft_strequ(av[1], "-d"))
	{
		data->flag = 'd';
		return (1);
	}
	return (0);
}

void dump_separator(int counter)
{
	if (counter == 0)
		ft_putstr("\n          Magic number\n\n");
	else if (counter == MAGIC_SPACE)
		ft_putstr("\n          Name\n\n");
	else if (counter == MAGIC_SPACE + NAME_SPACE)
		ft_putstr("\n          Comment\n\n");
	else if (counter == MAGIC_SPACE + NAME_SPACE + LENGTH_SPACE + COMMENT_SPACE)
		ft_putstr("\n          Program instructions\n\n");
}

int dump_dump(t_data *data, int fd)
{
	char	buf[4];
	int		counter;
	int		stored;
	int		i;

	if ((fd = open(data->file_name, O_RDONLY)) == -1)
		return (0);
	counter = 0;
	while ((stored = read(fd, &buf, 4)) > 0)
	{
		dump_separator(counter);
		if (stored == 4)
			ft_printf("%.8x | %.2hhx %.2hhx %.2hhx %.2hhx\n",
					counter, buf[0], buf[1], buf[2], buf[3]);
		else
		{
			ft_printf("%.8x | ", counter);
			i = 0;
			while (stored-- >= 0)
				ft_printf("%.2hhx ", buf[i++]);
		}
		counter += 4;
	}
	close(fd);
	return (stored != -1);
}
