#include "vector.h"

int		ft_get_element(const t_vector	vector, size_t	index)
{
	if (vector.elements != NULL)
		return (vector.elements[index]);
	return (INT_MIN);
}

int		ft_get_back(const t_vector vector)
{
	if (vector.elements != NULL)
		return (vector.elements[vector.count - 1]);
	return (INT_MIN);
}

size_t	ft_get_count(const t_vector vector)
{
	if (vector.elements != NULL)
		return (vector.count);
	return (0);
}
