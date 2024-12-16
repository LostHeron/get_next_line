/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:21 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 13:16:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	int		fd;
	char	*first_line;

	if (argc == 1)
		file_name = "test.txt";
	else if (argc == 2)
		file_name = argv[1];
	else
		printf("wrong usage : ./get_next_line [file_name]\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("could not open file\n");
		return (0);
	}
	printf("APPEL GNl\n");
	first_line = get_next_line(fd);
	printf("SORTIE GNL\n");
	printf("first_line = '%s'\n", first_line);
	printf("APPEL GNl 2\n");
	first_line = get_next_line(fd);
	printf("SORTIE GNL 2\n");
	printf("first_line = '%s'\n", first_line);
	first_line = get_next_line(fd);
	printf("first_line = '%s'\n", first_line);
	first_line = get_next_line(fd);
	printf("first_line = '%s'\n", first_line);
	/*
	if (first_line == NULL)
	{
		printf("get_next_line return 'NULL'\n'");
		return (0);
	}
	else
	{
		printf("first_line = '%s'\n", first_line);
	}
	*/
	return (0);
}
