/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:41 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 16:47:29 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_state
{
	char	*buf;
	size_t	bytes;
}	t_gnl_state;

void	ft_store_buffer(size_t read_bytes, char *new_buf);
char	*ft_sjoin(char *src, size_t src_byte, char *dest, size_t dest_byte);
char	*ft_substr(char *src, size_t start, size_t bytes);
char	*ft_get_line(void);
ssize_t	ft_read(int fd);

#endif
