/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:58:03 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/08 12:29:01 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	bag[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (bag[i])
		{
			bag[i] = 0;
			i++;
		}
		return (NULL);
	}
	line = NULL;
	while (*bag || read(fd, bag, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_gnl(line, bag);
		if (ft_reset(bag))
			break;
	}
	return (line);
}
