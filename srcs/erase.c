#include "vector.h"

bool	ft_erase(t_vector	*vector, size_t index)
{
	size_t	i;
	size_t	j;
	int		*result;

	if (vector->elements == NULL || index >= vector->count)
		return false;
	result = (int *)malloc(sizeof(int) * (vector->count - 1));
	i = 0;
	j = 0;
	while (j < vector->count)
	{
		if (i == index)
			++j;
		if (i >= vector->count)
			break;
		result[i++] = vector->elements[j++];
	}
	free(vector->elements);
	vector->count -= 1;
	vector->elements = result;
	return (true);
}

bool	ft_erase_back(t_vector	*vector)
{
	size_t	i;
	int		*result;

	if (vector->elements == NULL)
		return false;
	if (vector->count == 1)
	{
		vector->count = 0;
		free(vector->elements);
		vector->elements = NULL;
		return true;
	}
	result = (int *)malloc(sizeof(int) * (vector->count - 1));
	i = 0;
	while (i < vector->count - 1)
	{
		result[i] = vector->elements[i];
		++i;
	}
	free(vector->elements);
	vector->count -= 1;
	vector->elements = result;
	return (true);
}
