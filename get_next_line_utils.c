/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:57:30 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/08 15:35:29 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	return (i);
}

char *ft_strjoin_gnl(char *line, char *bag)
{
	char	*final;
	size_t	i;
	size_t	j;

	if (!bag)
		return (NULL);
	final = malloc(ft_strlen_gnl(line) + ft_strlen_gnl(bag) + 1);
	if (!final)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		final[i] = line[i];
		i++;
	}
	j = 0;
	while (bag[j] && bag[j] != '\n')
		final[i++] = bag[j++];
	if (bag[j] == '\n')
		final[i++] = '\n';
	final[i] = '\0';
	free(line);
	return (final);
}
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tempsrc;
	char	*tempdest;
	size_t	i;

	i = 0;
	tempsrc = (char *) src;
	tempdest = (char *) dest;
	if (tempdest > tempsrc)
	{
		while (len > 0)
		{
			len--;
			tempdest[len] = tempsrc[len];
		}
	}
	else
	{
		while (i < len)
		{
			tempdest[i] = tempsrc[i];
			i++;
		}
	}
	return (dest);
}
int ft_reset(char *bag)
{
	char *nl;
	
	nl = strchr(bag, '\n');
	if (!nl) {
		bag[0] = '\0';
		return 0;
	}
	size_t remaining_len = strlen(nl + 1);
	ft_memmove(bag, nl + 1, remaining_len + 1);
	return (1);
}
