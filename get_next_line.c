/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:37 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/15 21:29:53 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *leftover;
//Allowed functions - read, malloc, free
//ssize_t read(int fd, void buf[.count], size_t count);
char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	size_t	index;
	char	*s1;

	index = 0;
	s1 = (char *)malloc(BUFFER_SIZE);
	if (!s1)
		return (NULL);
	bytes_read = read(fd, s1, BUFFER_SIZE);
	if (bytes_read > 0)
	{

	}
}
