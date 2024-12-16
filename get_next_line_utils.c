/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:09:44 by jweber            #+#    #+#             */
/*   Updated: 2024/12/13 15:09:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* called only when buffer size is 0 at call of GNL */
char	*get_string_iter(int fd, t_list **plst, char *buff)
{
	int	nb_read;
	int	check_eol;

	//printf("entree dans get_string_iter\n");
	printf("ON LIT MAINTENANT 1\n");
	nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read <= 0)
		return (NULL);
	check_eol = 0;
	while (nb_read == BUFFER_SIZE && check_eol == 0)
	{
		if (add_node_change_buff(plst, buff, &check_eol) == NULL)
			return (NULL);
		printf("ON LIT MAINTENANT 2\n");
		nb_read = read(fd, buff, BUFFER_SIZE);
	}
	if (nb_read < 0)
		return (NULL);
	if (check_eol == 0)
	{
		//printf("############### ICI ################\n");
		if (add_node_change_buff(plst, buff, &check_eol) == NULL)
			return (NULL);
	}
	return (get_string(plst));
}
