/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:51 by illarion          #+#    #+#             */
/*   Updated: 2022/08/16 14:44:09 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include "utilities.h"

void	ft_reserve(t_vector	*vector, size_t capacity)
{
	void	*storage;

	if (vector == NULL || vector->capacity >= capacity || capacity == 0)
		return ;
	storage = (void *)malloc(vector->size_element * capacity);
	if (storage == NULL)
		return ;
	if (vector->count_elements != 0)
	{
		if (ft_vector_memcpy(storage, vector->storage, vector->size_element
				* vector->count_elements) != NULL)
			ft_vector_smart_free((void **)&vector->storage);
	}
	vector->storage = storage;
	vector->capacity = capacity;
}
