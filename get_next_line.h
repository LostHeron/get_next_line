/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:56:08 by jweber            #+#    #+#             */
/*   Updated: 2024/12/12 16:57:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	int				tot_len;
	struct s_list	*last;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int	fd);
void	lst_print(t_list *lst);
char	*get_string(t_list **plst);
void	*lst_clear(t_list **plst);
char	*get_string_iter(int fd, t_list **plst, char *buff);
char	*add_node_change_buff(t_list **plst, char *buff, int *check_eol);
void	*new_node(t_list **plst, char *content, int len_content);
void	change_buff(char *buff, int i);

#endif
