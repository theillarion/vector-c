#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include "utilities.h"

typedef struct s_vector
{
	void	*storage;
	unsigned short	size_element;
	size_t	capacity;
	size_t	count_elements;
	size_t	max_count_elements;
}			t_vector;

//		init.c
void	ft_init(t_vector	*vector, unsigned short size_element);

//		reserve.c
void	ft_reserve(t_vector	*vector, size_t	capacity);

//		resize.c
void	ft_resize(t_vector	*vector, size_t count, void	*element);

//		get.c
void	*ft_front(const t_vector	*vector);
void	*ft_back(const t_vector	*vector);
void	*ft_get_element(const t_vector	*vector, size_t index);
size_t	ft_size(const t_vector	*vector);
size_t	ft_capacity(const t_vector	*vector);

//		push.c
void 	ft_push_back(t_vector	*vector, void	*element);

//		erase.c
void	ft_erase(t_vector	*vector, size_t index);
void	ft_erase_front(t_vector	*vector);
void	ft_erase_back(t_vector	*vector);
void	ft_erase_all(t_vector	*vector);

//		empty.c
bool	ft_empty(const t_vector	*vector);

#endif