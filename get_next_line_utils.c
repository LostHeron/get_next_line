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

char	*get_string(t_list **plst)
{
	char	*res;
	t_list	*tmp;
	int		i;
	int		j;

	res = malloc(((*plst)->last->tot_len + 1) * sizeof(char));
	if (res == NULL)
		return ((char *) lst_clear(plst));
	tmp = *plst;
	i = 0;
	while (tmp != NULL)
	{
		j = 0;
		while ((tmp->content)[j])
		{
			res[i] = (tmp->content)[j];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	res[i] = '\0';
	lst_clear(plst);
	return (res);
}

/*
void	lst_print(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("element : %i : '%s'\n", i, lst->content);
		i++;
		lst = (*lst).next;
	}
}
*/

void	*lst_clear(t_list **plst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *plst;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1->content);
		free(tmp1);
		tmp1 = tmp2;
	}
	*plst = NULL;
	return (NULL);
}

/* called only when buffer size is 0 at call of GNL */
char	*get_string_iter(int fd, t_list **plst, char *buff, int check_eol)
{
	int	nb_read;

	nb_read = BUFFER_SIZE;
	while (nb_read == BUFFER_SIZE && check_eol == 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		printf("nb_read = %i\n", nb_read);
		if (nb_read < 0)
			return (lst_clear(plst));
		if (add_node_change_buff(plst, buff, &check_eol) == NULL)
			return (NULL);
	}
	if (nb_read < 0)
		return (NULL);
	if (check_eol == 0)
	{
		if (add_node_change_buff(plst, buff, &check_eol) == NULL)
			return (NULL);
	}
	return (get_string(plst));
}
