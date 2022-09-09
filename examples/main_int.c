/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <glashli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:21 by illarion          #+#    #+#             */
/*   Updated: 2022/09/09 23:15:54 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector.h"

void	ft_my_push_back(t_vector	*vector, int element)
{
	ft_push_back(vector, (void *)&element);
}

void	ft_output_vector(t_vector	*vector)
{
	size_t		i;

	i = 0;
	while (i < ft_size(vector))
	{
		printf("Element #%zu: %d\n", i, *(int *)ft_get_element(vector, i));
		++i;
	}
	if (ft_empty(vector))
		printf("Empty vector\n");
	printf("\n");
}

int	main(void)
{
	t_vector	vector;
	int			number;

	number = 777;
	ft_init_vector(&vector, sizeof(int), NULL);

	ft_reserve(&vector, 6);

	ft_output_vector(&vector);

	ft_push_back(&vector, (void *)&number);
	ft_my_push_back(&vector, 3);
	ft_my_push_back(&vector, INT32_MIN);
	ft_my_push_back(&vector, INT32_MAX);
	ft_my_push_back(&vector, 0);
	ft_my_push_back(&vector, -1);
	
	ft_output_vector(&vector);
	
	ft_erase_back(&vector);
	ft_erase_front(&vector);
	ft_erase(&vector, 2);
	
	ft_output_vector(&vector);
	
	ft_erase_all(&vector);
}
