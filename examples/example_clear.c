#include <stdio.h>
#include "vector.h"

typedef struct s_my_struct
{
	char	*name;
	int		age;
}	t_my_struct;

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char	*str)
{
	size_t	i;
	char	*new_str;

	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

t_my_struct	ft_create(int age, char *name)
{
	t_my_struct	result;

	result.name = ft_strdup(name);
	result.age = age;
	return (result);
}

void	ft_push(t_vector *vector, int age, char *name)
{
	t_my_struct element = ft_create(age, name);
	ft_push_back(vector, (void *)&element);
}

void ft_print(void *address)
{
	t_my_struct	element = *(t_my_struct *)address;

	printf("[Age: %d; Name: %s]\n", element.age, element.name);
}

void	ft_free_element(void *address)
{
	t_my_struct	element = *(t_my_struct *)address;
	free(element.name);
	element.name = NULL;
	element.age = 0;
}

int main()
{
	t_vector	vector;

	ft_init_vector(&vector, sizeof(t_my_struct), &ft_free_element);

	ft_push(&vector, 13, "Petr");
	ft_push(&vector, 15, "Vasya");
	ft_push(&vector, 17, "Igor");

	ft_foreach_vector(&vector, &ft_print);

	ft_erase(&vector, 1);

	printf("\n");
	ft_foreach_vector(&vector, &ft_print);

	ft_clear_vector(&vector);

	return (0);
}
