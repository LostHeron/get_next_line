/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:15:36 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:30:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	check_for_linefeed(char *buff, int *i)
{
	while (*i < BUFFER_SIZE && buff[*i] != '\n')
		(*i)++;
	if (buff[*i] == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	static t_list	*lst;
	static int		nb_read;
	char			*res;
	int				i;

	i = 0;
	while (buff[i])
		i++;
	if (i == 0)
		nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read == BUFFER_SIZE)
	{
		printf("dans 'nb_read == BUFFER_SIZE'\n");
		i = 0;
		if (check_for_linefeed(buff, &i) == 1)
		{
			add_maillon(&lst, buff);
			return (get_next_line(fd));
		}
		else
		{
			add_maillon(&lst, buff);
			return (get_string(&lst));
		}
	}
	else if (0 < nb_read && nb_read < BUFFER_SIZE)
	{
		printf("dans '0 < nb_read && nb_read < BUFFER_SIZE'\n");
		add_maillon(&lst, buff);
		res = get_string(&lst);
		printf("res dans gnl = '%s'\n", res);
		printf("puis on retourne la dans le main logiquement \n");
		return (res);
	}
	else if (nb_read == 0)
	{
		printf("dans 'nb_read == 0'\n");
		if (lst != NULL)
			return (get_string(&lst));
		else
			return (NULL);
	}
	else
	{
		ft_lst_clear(lst);
		return (NULL);
	}
	return (NULL);
}
