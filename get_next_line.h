/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:18:08 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 12:20:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	lst_print(t_list *lst);
t_list	*lst_clear(t_list *lst);
t_list	*add_node_change_buff(t_list **node, char *buff, int *check);
char	*get_string(t_list **plst);

#endif
