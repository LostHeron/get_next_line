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
		file_name = "test.txt";
	else if (argc == 2)
		file_name = argv[1];
	else
	{
		printf("wrong usage\n");
		return (1);
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	line_i = get_next_line(fd);
	printf("line_i (main) = '%s'\n", line_i);
	free(line_i);
	while (line_i != NULL)
	{
		line_i = get_next_line(fd);
		printf("i = %i, line_i (main) = '%s'\n", i, line_i);
		free(line_i);
		i++;
	}
	return (0);
}
