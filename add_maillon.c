/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_maillon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:28:14 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:43:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_maillon(t_list **plst, char *buff)
{
	t_list	*new;
	t_list	*tmp;
	char	*str;
	int		i;
	int		j;

	printf("\nentrée dans maillon\n");
	print_lst(*plst);
	new = malloc(sizeof(t_list));
	str = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		buff[i] = '\0';
		i++;
	}
	str[i] = buff[i];
	if (str[i++] == '\n')
		str[i] = '\0';
	j = i;
	while (buff[i])
	{
		buff[i - j] = buff[i];
		i++;
	}
	while (buff[i - j])
	{
		buff[i - j] = 0;
		i++;
	}
	new->content = str;
	if (*plst == NULL)
		*plst = new;
	else
	{
		tmp = *plst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	printf("sortie de maillon\n\n");
}
