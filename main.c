/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:55:33 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 17:01:14 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("could not open file \n");
			return (1);
		}
	}
	else
	{
		printf("wrong usage !\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("------------------line (main) = '%s'\n", line);
	free(line);
	line = get_next_line(fd);
	printf("------------------line (main) = '%s'\n", line);
	free(line);
	close(fd);
	line = get_next_line(fd);
	printf("------------------line (main) = '%s'\n", line);
	free(line);
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("could not open file \n");
			return (1);
		}
	}
	else
	{
		printf("wrong usage !\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("------------------line (main) = '%s'\n", line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("------------------line (main) = '%s'\n", line);
		free(line);
	}
	return (0);
}
