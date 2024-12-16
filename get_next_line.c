/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:01:26 by jweber            #+#    #+#             */
/*   Updated: 2024/12/13 15:11:02 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int	fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_list		*lst;
	int			check_eol;
	int			i;

	printf("entree get_next_line\n");
	printf("buff = '%s'\n", buff);
	i = 0;
	check_eol = 0;
	lst = NULL;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		i++;
		check_eol = 1;
	}
	if (i == 0)
	{
		printf(" ####on rentre dans i = 0 (car buffer vide)\n");
		return (get_string_iter(fd, &lst, buff));
	}
	else
	{
		printf(" ####on rentre dans i != 0 (car buffer non vide)\n");
		if (add_node_change_buff(&lst, buff, &check_eol) == NULL)
			return (NULL);
		return (get_string_iter(fd, &lst, buff));
	}
	/*
		nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read == 0)
	{
		if (lst == NULL)
			return (NULL);
		else
			return (get_string(&lst));
	}
	else if (nb_read < 0 &&)
		*/
}

char	*add_node_change_buff(t_list **plst, char *buff, int *check_eol)
{
	int		i;
	int		j;
	char	*str;

	printf("\n - entree add_node_change_buff\n");
	printf(" - buff = '%s'\n", buff);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		i++;
		*check_eol = 1;
	}
	//printf("buff = '%s'\n", buff);
	//printf("i = %i\n", i);
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (lst_clear(plst));
	j = -1;
	while (++j < i)
		str[j] = buff[j];
	str[j + 1] = '\0';
	if (new_node(plst, str, i) == NULL)
		return (NULL);
	change_buff(buff, i);
	printf(" %%%%%% buff at end of add node :\n");
	printf("buff = '%s'\n", buff);
	return (str);
}


void	change_buff(char *buff, int i)
{
	int	j;

	//printf("entree change_buff\n");
	j = 0;
	while (j < i)
	{
		buff[j] = buff[j + i];
		j++;
	}
	while (buff[j])
	{
		buff[j] = '\0';
		j++;
	}
}

/* create a new node out of content 
 * and free content in case of malloc faile */
void	*new_node(t_list **plst, char *content, int len_content)
{
	t_list	*new;

	//printf("entree new_node\n");
	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		free(content);
		return (lst_clear(plst));
	}
	//printf("apres creation node\n");
	(*new).content = content;
	//printf("apres content\n");
	(*new).next = NULL;
	//printf("apres next\n");
	if (*plst == NULL)
	{
		*plst = new;
		(*new).tot_len = len_content;
		(*new).last = new;
	}
	else
	{
		(*new).tot_len = (*(*plst)).last->tot_len + len_content;
		//printf("apres tot_len\n");
		(*(*plst)).last->next = new;
		(*(*plst)).last = new;
	}
	//printf("apres add_node\n");
	return (*plst);
}

void	*lst_clear(t_list **plst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	//printf("entree lst_clear\n");
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

char	*get_string(t_list **plst)
{
	char	*res;
	t_list	*tmp;
	int		i;
	int		j;
	
	//printf("entree get_string \n");
	//printf("~~~~~~~~~~~~~~~~~~\n");
	//printf("lst : \n");
	//lst_print(*plst);
	//printf("\n~~~~~~~~~~~~~~~~~~\n");
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
