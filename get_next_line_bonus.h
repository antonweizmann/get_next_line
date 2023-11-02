/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:08:50 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/02 12:03:41 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *str);

void	ft_bzero(void *str, size_t len);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *str, int c);

void	*ft_calloc(size_t count, size_t size);

#endif
