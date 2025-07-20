/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:37 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 20:26:21 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_store_buffer(size_t r_bytes, char *new_buf, t_gnl_state *g_ste)
{
	size_t	index;
	char	*temp_buf;

	index = 0;
	if (g_ste -> bytes == 0)
	{
		g_ste -> buf = (char *)malloc(r_bytes + 1);
		if (!g_ste -> buf)
			return ;
		while (index < r_bytes)
		{
			g_ste -> buf[index] = new_buf[index];
		}
		g_ste -> buf[index] = '\0';
	}
	else
	{
		temp_buf = ft_sjoin(new_buf, r_bytes, g_ste -> buf, g_ste -> bytes);
		free(g_ste -> buf);
		g_ste -> buf = ft_substr(temp_buf, 0, g_ste -> bytes + r_bytes);
		free(temp_buf);
	}
	g_ste -> bytes += r_bytes;
}

ssize_t	ft_read(int fd, t_gnl_state *g_ste)
{
	char	*new_buf;
	ssize_t	r_bytes;

	new_buf = (char *)malloc(BUFFER_SIZE);
	if (!new_buf)
		return (-1);
	r_bytes = read(fd, new_buf, BUFFER_SIZE);
	if (r_bytes > 0)
		ft_store_buffer((size_t)r_bytes, new_buf, g_ste);
	else if (r_bytes == 0)
	{
		g_ste -> bytes = 0;
		free(new_buf);
		return (0);
	}
	free(new_buf);
	return (r_bytes);
}

char	*ft_get_line(t_gnl_state *g_ste)
{
	size_t	index;
	char	*new_line;
	char	*temp_buf;

	index = 0;
	while (index < g_ste -> bytes)
	{
		if (g_ste -> buf[index] == '\n')
		{
			index++;
			break ;
		}
		index++;
	}
	new_line = ft_substr(g_ste -> buf, 0, index);
	g_ste -> bytes -= index;
	temp_buf = ft_substr(g_ste -> buf, index, g_ste -> bytes);
	free(g_ste -> buf);
	g_ste -> buf = ft_substr(temp_buf, 0, g_ste -> bytes);
	free(temp_buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	size_t				index;
	ssize_t				r_bytes;
	static t_gnl_state	g_ste;

	if (g_ste.bytes == 0)
		r_bytes = ft_read(fd, &g_ste);
	while (g_ste.bytes)
	{
		index = 0;
		r_bytes = 0;
		while (index < g_ste.bytes && g_ste.bytes > 0)
		{
			if (g_ste.buf[index] == '\n')
				return (ft_get_line(&g_ste));
			index++;
		}
		r_bytes = ft_read(fd, &g_ste);
		if (r_bytes == 0)
			return (g_ste.buf);
		if (r_bytes == -1)
			return (NULL);
	}
	return (NULL);
}
