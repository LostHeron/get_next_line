/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:40:48 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 08:42:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*lst_clear(t_list *lst)
{
	if (lst != NULL)
	{
		lst_clear(lst->next);
		free(lst->content);
		free(lst);
	}
	return (NULL);
}
