/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 17:57:06 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sjoin(char *src, size_t src_byte, char *dest, size_t dest_byte)
{
	char	*temp_buf;
	size_t	index;

	temp_buf = (char *)malloc(src_byte + dest_byte);
	if (!temp_buf)
		return (NULL);
	index = 0;
	while (index < dest_byte)
	{
		temp_buf[index] = dest[index];
		index++;
	}
	index = 0;
	while (index < src_byte)
	{
		temp_buf[dest_byte + index] = src[index];
		index++;
	}
	return (temp_buf);
}

char	*ft_substr(char *src, size_t start, size_t bytes)
{
	size_t	index;
	char	*temp_buf;

	if (bytes == 0)
		return (NULL);
	temp_buf = (char *)malloc(bytes + 1);
	if (!temp_buf)
		return (NULL);
	index = 0;
	while (index < bytes)
	{
		temp_buf[index] = src[start + index];
		index++;
	}
	temp_buf[index] = '\0';
	return (temp_buf);
}
