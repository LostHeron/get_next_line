/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_change_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:26:13 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 10:38:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*add_node_change_buff(t_list **node, char *buff, int *check)
{
	int		size_malloc;
	int		i;
	char	*str;
	t_list	*new;
	t_list	*tmp;

	//printf("buffer au debut de la fonction : '%s'\n", buff);
	/* creating new node */
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	/* getting size to malloc */
	size_malloc = 0;
	while (buff[size_malloc] && buff[size_malloc] != '\n')
		size_malloc++;
	if (buff[size_malloc] == '\n')
	{
		*check = 1;
		size_malloc++;
	}
	/* copy of this to str */
	str = malloc((size_malloc + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size_malloc)
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	(*new).content = str;
	(*new).next = NULL;
	/* modifying buffer to move all to start */
	i = 0;
	while (buff[size_malloc + i])
	{
		buff[i] = buff[size_malloc + i];
		i++;
	}
	/* clearing all rest to '\0' */
	while (buff[i])
	{
		buff[i] = '\0';
		i++;
	}
	/* creating node and adding it to lst */
	if (*node == NULL)
		*node = new;
	else
	{
		tmp = *node;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*tmp).next = new;
	}
	//printf("buffer a la fin de la fonction : '%s'\n", buff);
	return (*node);
}
