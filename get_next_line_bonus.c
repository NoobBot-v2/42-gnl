/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:37 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 18:00:03 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_gnl_state	g_ste[FD_MAX];

void	ft_store_buffer(size_t r_bytes, char *new_buf, int fd)
{
	size_t	index;
	char	*temp_buf;

	index = 0;
	if (g_ste[fd].bytes == 0)
	{
		g_ste[fd].buf = (char *)malloc(r_bytes + 1);
		if (!g_ste[fd].buf)
			return ;
		while (index < r_bytes)
		{
			g_ste[fd].buf[index] = new_buf[index];
			index++;
		}
		g_ste[fd].buf[index] = '\0';
	}
	else
	{
		temp_buf = ft_sjoin(new_buf, r_bytes, g_ste[fd].buf, g_ste[fd].bytes);
		free(g_ste[fd].buf);
		g_ste[fd].buf = ft_substr(temp_buf, 0, g_ste[fd].bytes + r_bytes);
		free(temp_buf);
	}
	g_ste[fd].bytes += r_bytes;
}

ssize_t	ft_read(int fd)
{
	char	*new_buf;
	ssize_t	r_bytes;

	new_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buf)
		return (-1);
	r_bytes = read(fd, new_buf, BUFFER_SIZE);
	if (r_bytes > 0)
		ft_store_buffer((size_t)r_bytes, new_buf, fd);
	else if (r_bytes == 0)
	{
		g_ste[fd].bytes = 0;
		free(new_buf);
		return (0);
	}
	free(new_buf);
	return (r_bytes);
}

char	*ft_get_line(int fd)
{
	size_t	index;
	char	*new_line;
	char	*temp_buf;

	index = 0;
	while (index < g_ste[fd].bytes)
	{
		if (g_ste[fd].buf[index] == '\n')
		{
			index++;
			break ;
		}
		index++;
	}
	new_line = ft_substr(g_ste[fd].buf, 0, index);
	g_ste[fd].bytes -= index;
	temp_buf = ft_substr(g_ste[fd].buf, index, g_ste[fd].bytes);
	free(g_ste[fd].buf);
	g_ste[fd].buf = ft_substr(temp_buf, 0, g_ste[fd].bytes);
	free(temp_buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	size_t	index;
	ssize_t	r_bytes;

	if (g_ste[fd].bytes == 0)
		r_bytes = ft_read(fd);
	while (g_ste[fd].bytes)
	{
		index = 0;
		r_bytes = 0;
		if (g_ste[fd].bytes > 0)
		{
			while (index < g_ste[fd].bytes)
			{
				if (g_ste[fd].buf[index] == '\n')
					return (ft_get_line(fd));
				index++;
			}
		}
		r_bytes = ft_read(fd);
		if (r_bytes == 0)
			return (g_ste[fd].buf);
		if (r_bytes == -1)
			return (NULL);
	}
	return (NULL);
}
