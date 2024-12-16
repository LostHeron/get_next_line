/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:42:46 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 10:43:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_string(t_list **plst)
{
	t_list	*tmp;
	char	*res;
	int		i;
	int		j;

	//printf("\nEntree get_string (lst)\n");
	//lst_print(*plst);
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
	//printf("tmp = '%p'\n", tmp);
	i = 0;
	while (tmp != NULL)
	{
		//printf("on rentre bien dans le while\n");
		j = 0;
		while (((char *)tmp->content)[j])
		{
			res[i] = ((char *)tmp->content)[j];
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	res[i] = '\0';
	*plst = lst_clear(*plst);
	//printf("res = '%s'\n", res);
	//printf("Sortie get_string (lst)\n\n");
	//printf("\n#########################\n");
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
