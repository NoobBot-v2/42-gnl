/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:37 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/15 22:53:19 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *leftover;

char	*ft_check_newline(char *new_data, char *leftover)
{
	size_t	index;
	size_t	len_leftover;
	char	*line;

	len_leftover = ft_strlen(leftover);
	while (index < BUFFER_SIZE)
	{
		//If end of a line
		if (new_data[index] = '\n')
		{
			line = (char *)malloc(index + len_leftover + 1);
			if (!line)
				return (NULL);
			//Combine leftover and new_data
			ft_strlcpy(line, leftover, index);
			ft_strlcat(line, new_data, index + len_leftover + 1);
			return (line);
		}
	}
	//If it reaches here, store current data into the static variable
	return (NULL);
}

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
