/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:06:19 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/31 22:44:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int		fd;
	t_data	data;

	data_initialize(&data);
	if ((ac != 2 && !dump_flag_management(&data, ac, av))
		|| !error_wrong_extension(av[1 + (data.flag != 0)]))
	{
		ft_printf("usage: ./asm [-d] filename.s\n");
		return (1);
	}
	if ((fd = open(av[1 + (data.flag != 0)], O_RDONLY)) == -1)
	{
		ft_printf("error in file opening\n");
		return (2);
	}
	if (!reader_read(fd, &data)
		|| !lines_review(&data)
		|| !labels_replace(&data))
		error_exit(&data);
	close(fd);
	if (!file_write(&data, fd, av[1 + (data.flag != 0)])
		|| (data.flag == 'd' && !dump_dump(&data, fd)))
		error_exit(&data);
	data_free(&data);
	return (0);
}
