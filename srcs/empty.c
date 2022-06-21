#include "vector.h"

bool	ft_empty(const t_vector	*vector)
{
	return (vector == NULL || vector->count_elements == 0);
}
