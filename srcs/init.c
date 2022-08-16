/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:46 by illarion          #+#    #+#             */
/*   Updated: 2022/08/16 14:44:58 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_init_vector(t_vector	*vector, unsigned short size_element)
{
	if (vector == NULL)
		return ;
	vector->storage = NULL;
	vector->size_element = size_element;
	vector->count_elements = 0;
	vector->max_count_elements = INT32_MAX;
	vector->capacity = 0;
}
