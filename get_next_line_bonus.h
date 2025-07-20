/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:53:41 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/20 16:56:51 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_state
{
	char	*buf;
	size_t	bytes;
}	t_gnl_state;

void	ft_store_buffer(size_t read_bytes, char *new_buf, int fd);
char	*ft_sjoin(char *src, size_t src_byte, char *dest, size_t dest_byte);
char	*ft_substr(char *src, size_t start, size_t bytes);
char	*ft_get_line(int fd);
ssize_t	ft_read(int fd);

#endif
