/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:38:40 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 12:48:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*new_node(t_list **plst, char *str, int len)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	(*new).content = str;
	(*new).next = NULL;
	if (*plst == NULL)
	{
		*plst = new;
		(*plst)->last = new;
		(*plst)->tot_len = len;
	}
	else
	{
		(*new).tot_len = (*plst)->last->tot_len + len;
		(*plst)->last->next = new;
		(*plst)->last = new;
	}
	return (new);
}

void	change_buff(char *buff, int index)
{
	int	j;

	j = 0;
	while (buff[index + j])
	{
		buff[j] = buff[index + j];
		j++;
	}
	while (buff[j])
	{
		buff[j] = '\0';
		j++;
	}
	return ;
}

void	buff_clear(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
	return ;
}

void	*lst_clear(t_list **plst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *plst;
	tmp2 = tmp1;
	while (tmp2 != NULL)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		free(tmp1->content);
		free(tmp1);
	}
	*plst = NULL;
	return (NULL);
}
