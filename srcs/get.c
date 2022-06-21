#include "vector.h"

void	*ft_get_element(const t_vector	*vector, size_t index)
{
	if (vector == NULL || vector->storage == NULL
		|| index > vector->count_elements)
		return (NULL);
	return ((void *)((t_uchar *)vector->storage
		+ (index * vector->size_element)));
}

void	*ft_back(const t_vector	*vector)
{
	if (vector == NULL || vector->storage == NULL)
		return (NULL);
	return ((void *)((t_uchar *)vector->storage + ((vector->count_elements - 1)
		* vector->size_element)));
}

void	*ft_front(const t_vector	*vector)
{
	if (vector == NULL || vector->storage == NULL)
		return (NULL);
	return (vector->storage);
}

size_t	ft_size(const t_vector	*vector)
{
	if (vector == NULL)
		return (0);
	return (vector->count_elements);
}

size_t	ft_capacity(const t_vector	*vector)
{
	if (vector == NULL)
		return (0);
	return (vector->capacity);
}
