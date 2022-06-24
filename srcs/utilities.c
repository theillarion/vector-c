#include "utilities.h"

void	*ft_vector_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((t_uchar *)dst)[i] = ((t_uchar *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_vector_memmove(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			((t_uchar *)dst)[i] = ((t_uchar *)src)[i];
			++i;
		}
	}
	else
	{
		while (n--)
			((t_uchar *)dst)[n] = ((t_uchar *)src)[n];
	}
	return (dst);
}

void	*ft_vector_memset(void	*address, int code, size_t n)
{
	size_t	i;

	if (address == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((t_uchar *)address)[i] = (t_uchar)code;
		i++;
	}
	return (address);
}

void	ft_vector_smart_free(void	**address)
{
	if (address == NULL || *address == NULL)
		return;
	free(*address);
	*address = NULL;
}
