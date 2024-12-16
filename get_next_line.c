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

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_list		*lst;
	int			check_eol;
	int			i;

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
		return (get_string_iter(fd, &lst, buff, 0));
	else
	{
		if (add_node_change_buff(&lst, buff, &check_eol) == NULL)
			return (NULL);
		return (get_string_iter(fd, &lst, buff, check_eol));
	}
}

char	*add_node_change_buff(t_list **plst, char *buff, int *check_eol)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		i++;
		*check_eol = 1;
	}
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (lst_clear(plst));
	j = -1;
	while (++j < i)
		str[j] = buff[j];
	str[j] = '\0';
	if (new_node(plst, str, i) == NULL)
		return (NULL);
	change_buff(buff, i);
	return (str);
}

void	change_buff(char *buff, int i)
{
	int	j;

	j = 0;
	while (buff[j + i])
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

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		free(content);
		return (lst_clear(plst));
	}
	(*new).content = content;
	(*new).next = NULL;
	if (*plst == NULL)
	{
		*plst = new;
		(*new).tot_len = len_content;
		(*new).last = new;
	}
	else
	{
		(*new).tot_len = (*(*plst)).last->tot_len + len_content;
		(*(*plst)).last->next = new;
		(*(*plst)).last = new;
	}
	return (*plst);
}
