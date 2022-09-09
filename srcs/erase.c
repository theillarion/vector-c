/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:41 by illarion          #+#    #+#             */
/*   Updated: 2022/09/09 23:10:06 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utilities.h"

void	ft_erase(t_vector	*vector, size_t index)
{
	if (vector == NULL || index >= vector->count_elements)
		return ;
	if (vector->destructor)
		(*vector->destructor)((t_uchar *)vector->storage
			+ (index * vector->size_element));
	if (ft_vector_memmove((t_uchar *)vector->storage
			+ (index * vector->size_element),
			(t_uchar *)vector->storage + ((index + 1)
				* vector->size_element),
			(vector->count_elements - (index + 1)) * vector->size_element))
			--vector->count_elements;
}

void	ft_erase_back(t_vector	*vector)
{
	ft_erase(vector, vector->count_elements - 1);
}

void	ft_erase_front(t_vector	*vector)
{
	ft_erase(vector, 0);
}

//		! Deprecated function !
void	ft_erase_all(t_vector	*vector)
{
	if (vector == NULL)
		return ;
	ft_foreach_vector(vector, vector->destructor);
	ft_vector_smart_free((void **)&vector->storage);
	vector->count_elements = 0;
	vector->capacity = 0;
}
