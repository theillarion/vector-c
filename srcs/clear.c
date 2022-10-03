/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:07:36 by illarion          #+#    #+#             */
/*   Updated: 2022/10/03 19:28:02 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "utilities.h"

void	ft_clear_vector(t_vector	*vector)
{
	ft_foreach_vector(vector, vector->destructor);
	vector->count_elements = 0;
	vector->capacity = 0;
	ft_vector_smart_free((void **)&vector->storage);
}
