#include "vector.h"
#include <stdio.h>

int main()
{
	t_vector	vector;

	ft_push_back(&vector, 5);
	ft_push_back(&vector, -100);
	ft_push_back(&vector, 0);
	ft_push_back(&vector, 0);
	ft_push_back(&vector, 9);
	
	ft_print_vector(vector);

	printf("Deleted: [4]\n");
	ft_erase(&vector, 4);
	ft_print_vector(vector);

	printf("Deleted: [0]\n");
	ft_erase(&vector, 0);
	ft_print_vector(vector);

	printf("Deleted: [2]\n");
	ft_erase(&vector, 2);
	ft_print_vector(vector);

	printf("Deleted: [1]\n");
	ft_erase(&vector, 1);
	ft_print_vector(vector);

	printf("Deleted: [0]\n");
	ft_erase(&vector, 0);
	ft_print_vector(vector);
	//size_t	i = 0;
	
	return (0);
}