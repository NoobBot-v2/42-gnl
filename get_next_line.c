/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:37 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 17:58:53 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_state	g_store;

void	ft_store_buffer(size_t read_bytes, char *new_buf)
{
	size_t	index;
	char	*temp_buf;

	index = 0;
	if (g_store.bytes == 0)
	{
		g_store.buf = (char *)malloc(read_bytes + 1);
		if (!g_store.buf)
			return ;
		while (index < read_bytes)
		{
			g_store.buf[index] = new_buf[index];
			index++;
		}
		g_store.buf[index] = '\0';
	}
	else
	{
		temp_buf = ft_sjoin(new_buf, read_bytes, g_store.buf, g_store.bytes);
		free(g_store.buf);
		g_store.buf = ft_substr(temp_buf, 0, g_store.bytes + read_bytes);
		free(temp_buf);
	}
	g_store.bytes += read_bytes;
}

ssize_t	ft_read(int fd)
{
	char	*new_buf;
	ssize_t	read_bytes;

	new_buf = (char *)malloc(BUFFER_SIZE);
	if (!new_buf)
		return (-1);
	read_bytes = read(fd, new_buf, BUFFER_SIZE);
	if (read_bytes > 0)
		ft_store_buffer((size_t)read_bytes, new_buf);
	else if (read_bytes == 0)
	{
		g_store.bytes = 0;
		free(new_buf);
		return (0);
	}
	free(new_buf);
	return (read_bytes);
}

char	*ft_get_line(void)
{
	size_t	index;
	char	*new_line;
	char	*temp_buf;

	index = 0;
	while (index < g_store.bytes)
	{
		if (g_store.buf[index] == '\n')
		{
			index++;
			break ;
		}
		index++;
	}
	new_line = ft_substr(g_store.buf, 0, index);
	g_store.bytes -= index;
	temp_buf = ft_substr(g_store.buf, index, g_store.bytes);
	free(g_store.buf);
	g_store.buf = ft_substr(temp_buf, 0, g_store.bytes);
	free(temp_buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	size_t	index;
	ssize_t	read_bytes;

	if (g_store.bytes == 0)
		read_bytes = ft_read(fd);
	while (g_store.bytes)
	{
		index = 0;
		read_bytes = 0;
		if (g_store.bytes > 0)
		{
			while (index < g_store.bytes)
			{
				if (g_store.buf[index] == '\n')
					return (ft_get_line());
				index++;
			}
		}
		read_bytes = ft_read(fd);
		if (read_bytes == 0)
			return (g_store.buf);
		if (read_bytes == -1)
			return (NULL);
	}
	return (NULL);
}
