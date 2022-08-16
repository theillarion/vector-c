/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:21 by illarion          #+#    #+#             */
/*   Updated: 2022/08/16 15:07:32 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector.h"

typedef struct s_point
{
	int x;
	int y;
}		t_point;

t_point	ft_create_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return point;
}

void	ft_my_push_back(t_vector	*vector, t_point point)
{
	ft_push_back(vector, (void *)&point);
}

t_point	ft_my_get_element(t_vector *vector, size_t index)
{
	return *(t_point *)ft_get_element(vector, index);
}

void	ft_output_vector(t_vector	*vector)
{
	size_t	i;
	t_point	point;

	i = 0;
	while (i < ft_size(vector))
	{
		point = ft_my_get_element(vector, i);
		printf("Element #%zu: [%d, %d]\n", i, point.x, point.y);
		++i;
	}
	if (ft_empty(vector))
		printf("Empty vector\n");
	printf("\n");
}

int	main(void)
{
	t_vector	vector;
	t_point		point;

	point = ft_create_point(7, 77);
	ft_init_vector(&vector, sizeof(t_point));

	ft_reserve(&vector, 6);

	ft_output_vector(&vector);

	ft_push_back(&vector, (void *)&point);
	ft_my_push_back(&vector, ft_create_point(0, 0));
	ft_my_push_back(&vector, ft_create_point(INT32_MIN, INT32_MAX));
	ft_my_push_back(&vector, ft_create_point(0, -100));
	ft_my_push_back(&vector, ft_create_point(127, 11));
	ft_my_push_back(&vector, ft_create_point(-1, -1));
	
	ft_output_vector(&vector);
	
	ft_erase_back(&vector);
	ft_erase_front(&vector);
	ft_erase(&vector, 2);
	
	ft_output_vector(&vector);
	
	ft_erase_all(&vector);
}
