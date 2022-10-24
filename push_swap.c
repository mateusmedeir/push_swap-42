#include "push_swap.h"

int	ft_check_sort(t_stack *stack)
{
	t_dolst  *tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_push_swap(char *values[], int size)
{
	struct s_stack	*a;
	struct s_stack	*b;

	a = ft_load_stack(values, size);
	if (!a)
		ft_error();
	b = ft_stack_new();
	if (!b)
		free(a);
	if (ft_check_sort(a))
		exit(EXIT_SUCCESS);
	else if (a->size <= 5)
		ft_sort_lower(a, b);
	else
		ft_sort(a, b);
}

int	main(int argc, char *argv[])
{
	char	**values;
	int	counter;

	if (argc > 1)
	{
		if (argc == 2)
		{
			values = ft_split(argv[1], ' ');
			counter = 0;
			while (values[counter])
				counter++;
			ft_push_swap(values, counter);
		}
		else
			ft_push_swap(argv + 1, argc - 1);
	}
}
