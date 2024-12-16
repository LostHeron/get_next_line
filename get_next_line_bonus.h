/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:48 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 16:46:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
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
void	*whil_read(int fd, t_list **pl, char (*bu)[BUFFER_SIZE + 1], int c_eol);
void	buff_clear(int fd, char (*buff)[BUFFER_SIZE + 1]);
void	*lst_clear(t_list **plst);
void	*add_buff(int fd, t_list **pl, char (*bu)[BUFFER_SIZE + 1], int *c_eol);
void	*new_node(t_list **plst, char *str, int len);
void	change_buff(int fd, char (*buff)[BUFFER_SIZE + 1], int index);
void	*get_string(t_list **plst);
char	*in_els(int fd, t_list **plst, char (*buf)[BUFFER_SIZE + 1], int c_eol);

#endif
