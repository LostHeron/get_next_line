/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:38:08 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:42:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		printf("element : %i : '%s'\n", i, (char *) lst->content);
		lst = lst->next;
	}
}
