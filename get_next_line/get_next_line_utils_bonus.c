/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-f <asousa-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:11:07 by asousa-f          #+#    #+#             */
/*   Updated: 2023/11/02 13:27:25 by asousa-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *sbuffer, char *tmpline)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!sbuffer)
	{
		sbuffer = malloc(sizeof(char) * 1);
		sbuffer[0] = '\0';
	}
	if (!sbuffer || !tmpline)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(sbuffer) + ft_strlen(tmpline) + 1));
	if (!str)
		return (0);
	while (sbuffer[++i] != '\0')
		str[i] = sbuffer[i];
	while (tmpline[j] != '\0')
		str[i++] = tmpline[j++];
	str[i] = '\0';
	free(sbuffer);
	return (str);
}
