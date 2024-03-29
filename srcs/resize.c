/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:53 by illarion          #+#    #+#             */
/*   Updated: 2022/08/16 14:42:38 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utilities.h"

void	ft_resize(t_vector	*vector, size_t count, void	*element)
{
	size_t	i;

	if (vector == NULL)
		return ;
	ft_vector_smart_free((void **)&vector->storage);
	if (count > vector->capacity)
		ft_reserve(vector, count);
	i = 0;
	while (i < count)
	{
		ft_vector_memcpy((t_uchar *)vector->storage
			+ (i * vector->size_element), element, vector->size_element);
		++i;
	}
	if (count < vector->count_elements)
		ft_vector_memset((t_uchar *)vector->storage
			+ (count * vector->size_element),
			'\0', (vector->count_elements - count) * vector->size_element);
	vector->count_elements = count;
}
