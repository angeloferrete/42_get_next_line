/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-f <asousa-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:54:13 by asousa-f          #+#    #+#             */
/*   Updated: 2023/11/02 15:06:38 by asousa-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*sbuffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sbuffer = ft_readfd(fd, sbuffer);
	if (!sbuffer)
		return (0);
	line = ft_saveline(sbuffer);
	sbuffer = ft_restline(sbuffer);
	return (line);
}

/*int	main(void)
{
	int	fd;
	char	*line;
	
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
        printf("%s", line);
        free(line);
	}
	close(fd);  
	return(0);
}*/