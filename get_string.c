/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:58:36 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:07:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_string(t_list **plst)
{
	t_list	*tmp;
	char	*res;
	int		i;
	int		j;

	printf("\nEntree get_string (lst)\n");
	i = 0;
	tmp = *plst;
	while (tmp != NULL)
	{
		j = 0;
		while (((char *)tmp->content)[j])
			j++;
		i += j;
		tmp = tmp->next;
	}
	res = malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	tmp = *plst;
	i = 0;
	while (tmp != NULL)
	{
		j = 0;
		while (((char *)tmp->content)[j])
		{
			res[i] = ((char *)tmp->content)[j];
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	*plst = ft_lst_clear(*plst);
	printf("Sortie get_string (lst)\n\n");
	printf("res = '%s'\n", res);
	return (res);
}


/*
int	main(void)
{
	t_list	*t1;
	t_list	*t2;
	t_list	*t3;
	char	arr1[] = "cou\nou";
	char	arr2[] = "toi";
	char	arr3[] = "bg";
	char	*str;

	t1 = malloc(sizeof(t_list));
	t2 = malloc(sizeof(t_list));
	t3 = malloc(sizeof(t_list));
	(*t1).next = t2;
	(*t2).next = t3;
	(*t3).next = NULL;
	(*t1).content = arr1;
	(*t2).content = arr2;
	(*t3).content = arr3;
	print_lst(t1);
	str = get_string(&t1);
	printf("str = '%s'\n", str);
}
*/
