#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
#include <stdbool.h>

typedef struct s_vector
{
	int		*elements;
	size_t	count;
}			t_vector;

void 	ft_push_back(t_vector	*vector, int element);
bool	ft_erase_back(t_vector	*vector);
bool	ft_erase(t_vector	*vector, size_t	index);
void	ft_print_vector(const t_vector vector);
int		ft_get_element(const t_vector vector, size_t index);
int		ft_get_back(const t_vector vector);
size_t	ft_get_count(const t_vector vector);
bool	ft_empty_vector(const t_vector vector);
//size_t	ft_get_count(t_vector	*vector);
//void	ft_erase_back(t_vector	*vector);
//int		ft_get_element(t_vector	*vector);

#endif

/*
	### FORBIDDEN FUNCTION: printf
*/