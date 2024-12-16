/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:09:06 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 10:16:14 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*line;
	int		*arr_fd;

	if (argc <= 1)
	{
		printf("wrond usage !\n");
		printf("usage : ./a.out file_1 file_2 ... file_n\n");
		return (1);
	}
	else
	{
		i = 0;
		arr_fd = malloc((argc - 1) * sizeof(int));
		printf("argc = %i\n", argc);
		while (i < argc - 1)
		{
			arr_fd[i] = open(argv[i + 1], O_RDONLY);
			printf("arr_fd[i] = %i\n", arr_fd[i]);
			if (arr_fd[i] < 0)
			{
				printf("could not open file '%s'\n", argv[i + 1]);
				j = 0;
				while (j < i)
				{
					close(arr_fd[j]);
					j++;
				}
				return (1);
			}
			i++;
		}
	}
	line = get_next_line(arr_fd[0]);
	printf("line (%i) = '%s'\n", arr_fd[0], line);
	free(line);
	line = get_next_line(arr_fd[1]);
	printf("line (%i) = '%s'\n", arr_fd[1], line);
	free(line);
	line = get_next_line(arr_fd[0]);
	printf("line (%i) = '%s'\n", arr_fd[0], line);
	free(line);
	line = get_next_line(arr_fd[1]);
	printf("line (%i) = '%s'\n", arr_fd[1], line);
	free(line);
}
