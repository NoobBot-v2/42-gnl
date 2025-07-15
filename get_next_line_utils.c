/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/15 22:53:07 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Check if input has '\n' and data after that
//If no '\n' store to leftover and continue reading
//Return the line if \n is found and store the data after that
//If there is leftover, it should always go to the front
size_t	ft_strlen(char	*s1)
{
	size_t	count;

	count = 0;
	while (s1[count])
		count++;
	return (count);
}

static int	ft_has_term(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (!ft_has_term(dst, size))
		return (size + src_len);
	dst_len = ft_strlen(dst);
	if (size > dst_len)
	{
		while (i < (size - dst_len - 1) && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

