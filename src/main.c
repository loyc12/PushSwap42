/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/10/11 16:47:08 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void free_all(int flag, char **argv, int *list_a, int *list_b)
{
	int	i;

	i = -1;
	if (!(flag % 2))
	{
		while (argv[++i])
		{
			free(argv[i]);
		}
		free(argv);
	}
	if (!(flag % 3))
		free(list_a);
	if (!(flag % 5))
		free(list_b);
}

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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*list;
	int		flag;

	flag = 1;
	argv += 1;
	list = NULL;
	if (--argc == 1)
		argv = ft_split(argv[0], ' ', &argc, &flag);
	if (format_filter(argv, argc))
	{
		list = lister(list, argv, argc);
		list = indexer(list, argc);
		if (value_filter(list, argc))
			if (!is_sorted(list, argc))
			{
				stack_a = stacker_a(&flag, list);
				stack_b = stacker_b(&flag, stack_a.max_lenght);
				sort_all(&stack_a, &stack_b);
			}
	}
	free_all(flag, argv, stack_a.list, stack_b.list);
	return (0);
}
