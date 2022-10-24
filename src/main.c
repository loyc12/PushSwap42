/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/10/24 08:51:27 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Frees all used memory
static void	free_all(int *flag, char **argv, int *list_a, int *list_b)
{
	int	i;

	i = -1;
	if (*flag % 2 == 0)
	{
		while (argv[++i])
		{
			free(argv[i]);
		}
		free(argv);
	}
	if (*flag % 3 == 0)
		free(list_a);
	if (*flag % 5 == 0)
		free(list_b);
}

// Sorts a given stack configuration
static void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	if (1 < (*stack_a).lenght)
	{
		if ((*stack_a).lenght < 3)
		{
			if ((*stack_a).list[0] == 2)
				ss(stack_a, stack_b, 0);
		}
		else if ((*stack_a).lenght < 7)
			small_sort(stack_a, stack_b);
		else
			big_sort(stack_a, stack_b);
	}
}

static void	main_loop(long *list, int argc, char **argv, int *flag)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (format_filter(argv, argc))
	{
		list = lister(list, argv, argc);
		value_limiter(list, argc, flag);
		list = indexer(list, argc);
		if (value_filter(list, argc, flag))
		{
			if (!is_sorted(list, argc))
			{
				stack_a = stacker_a(flag, list);
				stack_b = stacker_b(flag, stack_a.max_lenght);
				sort_all(&stack_a, &stack_b);
			}
		}
		free(list);
	}
	free_all(flag, argv, stack_a.list, stack_b.list);
}

int	main(int argc, char **argv)
{
	long	*list;
	int		flag;

	flag = 1;
	argv += 1;
	list = NULL;
	if (--argc == 1)
		argv = ft_split(argv[0], ' ', &argc, &flag);
	main_loop(list, argc, argv, &flag);
	return (0);
}
