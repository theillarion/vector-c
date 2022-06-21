#ifndef UTILITIES_H
# define UTILITIES_H

#include <stdlib.h>

typedef unsigned char	t_uchar;

void	*ft_memcpy(void	*dst, const void	*src, size_t n);
void	*ft_memmove(void	*dst, const void	*src, size_t n);
void	*ft_memset(void	*address, int code, size_t n);
void	ft_smart_free(void	**address);

#endif