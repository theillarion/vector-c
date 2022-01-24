#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_vector
{
	int		*elements;
	size_t	count;
}			t_vector;

void 	ft_push_back(t_vector	*vector, int element);
//size_t	ft_get_count(t_vector	*vector);
//void	ft_erase_back(t_vector	*vector);
//int		ft_get_element(t_vector	*vector);

#endif