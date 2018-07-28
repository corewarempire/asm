/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:06:19 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/26 19:06:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2 || !error_wrong_extension(av[1]))
	{
		ft_printf("usage: ./asm filename.s\n");
		return (1);
	}
	data_initialize(&data);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("error in file opening\n");
		return (2);
	}
	if (!reader_read(fd, &data) || !lines_review(&data)
		|| !labels_replace(&data))
		error_exit(&data);
	close(fd);
	if (!file_write(&data, fd, av[1]))
		error_exit(&data);
	data_free(&data);
	return (0);
}
