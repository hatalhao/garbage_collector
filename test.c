#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utiles.h"

// #include <stri.h>

// unsigned long	get_size(void *ptr)
// {
// 	return(sizeof(*ptr));
// }

int main()
{
	int		i = -1;
	// char	c;
	// char	*str;
	// char	**arr_str;
	int		*arr;
	t_node	**list;

	arr = 0;	
	printf("arr = %p\n", arr);
	list = malloc (sizeof(t_node *));
	*list = 0;
	ft_malloc (list, (void **)&arr, sizeof(int), 6);
	printf("arr = %p\n", arr);
	srand(time(NULL));
	while (++i < 6)
	{
		arr[i] = rand();
		printf("%p == arr[%d] == %d\n", &arr[i], i, arr[i]);
	}
	free_node(list, arr);
	free (list);
}