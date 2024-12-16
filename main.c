/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:17:34 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 10:43:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	char	*line_i;
	int		fd;
	int		i;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		file_name = argv[1];
		fd = open(file_name, O_RDONLY);
	}
	else
	{
		printf("wrong usage\n");
		return (1);
	}
	i = 0;
	/*
	while (i < 4)
	{
		line_i = get_next_line(fd);
		printf("i = %i, line_i (main) = '%s'\n", i, line_i);
		free(line_i);
		i++;
	}	
	*/
	line_i = get_next_line(fd);
	printf("i = %i, line_i (main) = '%s'\n", i, line_i);
	free(line_i);
	line_i = get_next_line(fd);
	printf("i = %i, line_i (main) = '%s'\n", i, line_i);
	free(line_i);
	close(fd);
	line_i = get_next_line(fd);
	printf("i = %i, line_i (main) = '%s'\n", i, line_i);
	free(line_i);
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		file_name = argv[1];
		fd = open(file_name, O_RDONLY);
	}
	else
	{
		printf("wrong usage\n");
		return (1);
	}
	line_i = get_next_line(fd);
	printf("i = %i, line_i (main) = '%s'\n", i, line_i);
	free(line_i);
	line_i = get_next_line(fd);
	printf("i = %i, line_i (main) = '%s'\n", i, line_i);
	free(line_i);
	return (0);
}
