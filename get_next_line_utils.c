/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:18:42 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 12:18:54 by jweber           ###   ########.fr       */
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
	{
		*plst = lst_clear(*plst);
		return (NULL);
	}
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

void	lst_print(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("element %i : '%s'\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	{
		free(new);
		return (NULL);
	}
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
