/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-f <asousa-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:53:53 by asousa-f          #+#    #+#             */
/*   Updated: 2023/11/02 12:04:26 by asousa-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_readfd(int fd, char *sbuffer);
char	*ft_saveline(char *sbuffer);
char	*ft_restline(char	*sbuffer);

size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *sbuffer, char *tmpline);

#endif