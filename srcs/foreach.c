/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:25:15 by illarion          #+#    #+#             */
/*   Updated: 2022/09/08 20:12:49 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utilities.h"

void	ft_foreach_vector(const t_vector *vector, void (*func)(void *))
{
	size_t	i;

	i = 0;
	if (func != NULL)
		while (i < vector->count_elements)
			(*func)((void *)((t_uchar *)vector->storage
					+ ((i++) * vector->size_element)));
}
