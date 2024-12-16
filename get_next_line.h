/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:14:37 by jweber            #+#    #+#             */
/*   Updated: 2024/12/11 17:07:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 6

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
char	*get_string(t_list **plst);
t_list	*ft_lst_clear(t_list *lst);
void	add_maillon(t_list **plst, char *buff);
void	print_lst(t_list *lst);

#endif
