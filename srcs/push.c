/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:48 by illarion          #+#    #+#             */
/*   Updated: 2022/08/16 14:49:20 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utilities.h"

void	ft_push_back(t_vector	*vector, void	*element)
{
	if (vector == NULL || vector->count_elements >= vector->max_count_elements)
		return ;
	if (vector->capacity == 0)
		ft_reserve(vector, 1);
	if (vector->count_elements >= vector->capacity)
		ft_reserve(vector, vector->capacity * 2);
	if (ft_vector_memcpy(((t_uchar *)vector->storage + (vector->count_elements
					* vector->size_element)), element, vector->size_element)
		!= NULL)
		++vector->count_elements;
}
