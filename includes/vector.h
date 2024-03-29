/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:35 by illarion          #+#    #+#             */
/*   Updated: 2022/09/23 23:19:14 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_vector
{
	void			*storage;
	unsigned short	size_element;
	size_t			capacity;
	size_t			count_elements;
	size_t			max_count_elements;
	void			(*destructor)(void *);
}					t_vector;

//		init.c
void	ft_init_vector(t_vector	*vector, unsigned short size_element,
			void (*destructor)(void *));

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
void	ft_push_back(t_vector	*vector, void	*element);

//		erase.c
void	ft_erase(t_vector	*vector, size_t index);
void	ft_erase_front(t_vector	*vector);
void	ft_erase_back(t_vector	*vector);

//		! Deprecated function !
void	ft_erase_all(t_vector	*vector);

//		empty.c
bool	ft_empty(const t_vector	*vector);

//		foreach.c
void	ft_foreach_vector(const t_vector *vector, void (*func)(void *));

//		clear.c
void	ft_clear_vector(t_vector	*vector);

#endif