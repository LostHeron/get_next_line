/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:23 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 10:25:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			i;
	int			check_eol;

	i = 0;
	check_eol = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		i++;
		check_eol = 1;
	}
}
