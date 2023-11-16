/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-f <asousa-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:06:46 by asousa-f          #+#    #+#             */
/*   Updated: 2023/11/02 12:05:37 by asousa-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfd(int fd, char *sbuffer)
{
	char	*tmpline;
	int		nbr_bytes;

	tmpline = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmpline)
		return (0);
	nbr_bytes = 1;
	while (!ft_strchr(sbuffer, '\n') && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, tmpline, BUFFER_SIZE);
		if (nbr_bytes == -1)
		{
			free(tmpline);
			free(sbuffer);
			return (0);
		}
		tmpline[nbr_bytes] = '\0';
		sbuffer = ft_strjoin(sbuffer, tmpline);
	}
	free(tmpline);
	return (sbuffer);
}

char	*ft_saveline(char *sbuffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!sbuffer[i])
		return (0);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
	{
		str[i] = sbuffer[i];
		i++;
	}
	if (sbuffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_restline(char	*sbuffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!sbuffer)
		return (0);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	while (!sbuffer[i] || sbuffer[i + 1] == '\0')
	{
		free(sbuffer);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(sbuffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (sbuffer[i])
		str[j++] = sbuffer[i++];
	str[j] = '\0';
	free(sbuffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*sbuffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sbuffer[fd] = ft_readfd(fd, sbuffer[fd]);
	if (!sbuffer[fd])
		return (0);
	line = ft_saveline(sbuffer[fd]);
	sbuffer[fd] = ft_restline(sbuffer[fd]);
	return (line);
}
