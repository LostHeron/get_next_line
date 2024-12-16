/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:59:28 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:05:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lst_clear(t_list *lst)
{
	if (lst != NULL)
	{
		ft_lst_clear(lst->next);
		free(lst->content);
		free(lst);
	}
	return (NULL);
}
