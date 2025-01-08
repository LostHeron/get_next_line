/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:23 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 16:47:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	t_list		*lst;
	int			i;
	int			check_eol;

	i = 0;
	check_eol = 0;
	lst = NULL;
	while (buff[fd][i] && buff[fd][i] != '\n')
		i++;
	if (buff[fd][i] == '\n')
	{
		i++;
		check_eol = 1;
	}
	if (i == 0)
	{
		return (whil_read(fd, &lst, buff, check_eol));
	}
	else
	{
		return (in_els(fd, &lst, buff, check_eol));
	}
	return (NULL);
}

char	*in_els(int fd, t_list **plst, char (*buf)[BUFFER_SIZE + 1], int c_eol)
{
	if (c_eol == 1)
	{
		if (add_buff(fd, plst, buf, &c_eol) == NULL)
			return (lst_clear(plst));
		return (get_string(plst));
	}
	else
	{
		if (add_buff(fd, plst, buf, &c_eol) == NULL)
			return (lst_clear(plst));
		return (whil_read(fd, plst, buf, c_eol));
	}
}

void	*whil_read(int fd, t_list **pl, char (*bu)[BUFFER_SIZE + 1], int c_eol)
{
	int	nb_read;

	nb_read = BUFFER_SIZE;
	while (nb_read > 0 && c_eol == 0)
	{
		nb_read = read(fd, bu[fd], BUFFER_SIZE);
		if (nb_read < 0)
		{
			buff_clear(fd, bu);
			return (lst_clear(pl));
		}
		if (add_buff(fd, pl, bu, &c_eol) == NULL)
			return (lst_clear(pl));
	}
	return (get_string(pl));
}

void	*get_string(t_list **plst)
{
	char	*str;
	t_list	*tmp;
	int		i;
	int		j;

	str = malloc(((*plst)->last->tot_len + 1) * sizeof(char));
	if (str == NULL)
		return (lst_clear(plst));
	i = 0;
	tmp = *plst;
	while (tmp != NULL)
	{
		j = 0;
		while (tmp->content[j])
		{
			str[i] = tmp->content[j];
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	str[i] = '\0';
	lst_clear(plst);
	return (str);
}

void	*add_buff(int fd, t_list **pl, char (*bu)[BUFFER_SIZE + 1], int *c_eol)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (bu[fd][i] && bu[fd][i] != '\n')
		i++;
	if (bu[fd][i] == '\n')
	{
		*c_eol = 1;
		i++;
	}
	if (i == 0)
		return (*pl);
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = bu[fd][j];
	str[j] = '\0';
	if (new_node(pl, str, i) == NULL)
		return (NULL);
	change_buff(fd, bu, i);
	return (str);
}

/*
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
*/
