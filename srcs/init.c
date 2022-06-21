#include "vector.h"

void	ft_init(t_vector	*vector, unsigned short size_element)
{
	if (vector == NULL)
		return;
	vector->storage = NULL;
	vector->size_element = size_element;
	vector->count_elements = 0;
	vector->max_count_elements = SIZE_MAX;
	vector->capacity = 0;
}
