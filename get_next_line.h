/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:48 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 12:48:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	int				tot_len;
	struct s_list	*last;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	*while_read(int fd, t_list **plst, char *buff, int check_eol);
void	buff_clear(char *buff);
void	*lst_clear(t_list **plst);
void	*add_node_change_buff(t_list **plst, char *buff, int *check_eol);
void	*new_node(t_list **plst, char *str, int len);
void	change_buff(char *buff, int index);
void	*get_string(t_list **plst);
char	*in_else(int fd, t_list **plst, char *buff, int check_eol);

#endif
