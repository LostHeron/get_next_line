/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:17:52 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 10:46:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	static t_list	*lst;
	static int		nb_read;
	int				check_end;
	int				len_buff;

	check_end = 0;
	len_buff = ft_strlen(buff);
	if (len_buff == 0)
		nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read == 0)
	{
		//printf("dans nb_read == 0\n");
		if (lst == NULL)
			return (NULL);
		else
			return (get_string(&lst));
	}
	else if (0 < nb_read && nb_read < BUFFER_SIZE)
	{
		//printf("dans nb_read entre 0 et BUFFER_SIZE\n");
		if (add_node_change_buff(&lst, buff, &check_end) == NULL)
		{
			lst = lst_clear(lst);
			return (NULL);
		}
		return (get_string(&lst));
	}
	else if (nb_read == BUFFER_SIZE)
	{
		//printf("dans nb_read == BUFFER_SIZE\n");
		if (add_node_change_buff(&lst, buff, &check_end) == NULL)
		{
			lst = lst_clear(lst);
			return (NULL);
		}
		if (check_end == 1)
			return (get_string(&lst));
		else
			return (get_next_line(fd));
	}
	else
	{
		//printf("on est entré la mais bizare !!!!!!!!!!!!!!!!!!!!\n");
		lst = lst_clear(lst);
		int i = 0;
		while (buff[i])
		{
			buff[i] = '\0';
			i++;
		}
		return (NULL);
	}
}
