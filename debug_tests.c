/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/23 09:12:51 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stacks(t_stack *stack_a, t_stack *stack_b, int type)
{
	int	i;

	if (type == 0 || type == 2)			// Type : (0)/(2) = a
	{									// Prints the A stack
		printf("\n -A-  : ");					
		i = -1;
		while (++i < (*stack_a).max_lenght)
		{
			if ((*stack_a).pos == i)
				printf("> %i < ", (*stack_a).list[i]);
			else
				printf("%i ", (*stack_a).list[i]);
		}
		printf("\n size : %i of %i\n", (*stack_a).lenght, (*stack_a).max_lenght);
	}
	if (type == 1 || type == 2)			// Type : (1)/(2) = b
	{									// Prints the B stack
		printf("\n -B-  : ");
		i = -1;
		while (++i < (*stack_b).max_lenght)
		{
			if ((*stack_b).pos == i)
				printf("> %i < ", (*stack_b).list[i]);
			else
				printf("%i ", (*stack_b).list[i]);
		}
		printf("\n size : %i of %i\n", (*stack_b).lenght, (*stack_b).max_lenght);
	}

}

void	debug_print_end(t_stack *stack)
{
	int	i;
	int	j;

	i = (*stack).pos - 1;
	write(1, "\n", 1);
	while (++i < (*stack).lenght)
	{
		j = -1;
		write(1, "\n", 1);
		while (++j < (*stack).list[i])
			write(1, "#", 1);
	}
	i = -1;
	while (++i < (*stack).pos)
	{
		j = -1;
		write(1, "\n", 1);
		while (++j < (*stack).list[i])
			write(1, "#", 1);
	}
}

void	debug_print_str(char **list, int len, char *name)
{							// Prints a list of strings
	int	i;
	
	printf("\n%s : ", name);
	i = -1;
	while (++i < len)
		printf("\"%s\" ", list[i]);
}

void	debug_print_int(int *list, int len, char *name)
{							// Prints a list of ints
	int	i;
	
	printf("\n%s : ", name);
	i = -1;
	while (++i < len)
		printf(" %i  ", list[i]);
	printf("\n");
}

void	debug_print_dist(int distance_down, int distance_up)
{							// Prints the distances
	printf("\n Dist down : %i\n", distance_down);
	printf(" Dist up   : %i\n", distance_up);
}

void	debug_looks(t_stack *stack)
{							// Tests the looks
	printf("\n\n");			// Formating
	printf(" Distance  : %i\n", look_for(stack, 1, 1));
}

void	debug_moves(t_stack *stack_a, t_stack *stack_b)
{							// Tests the moves (and the mover)
	debug_print_stacks(stack_a, stack_b, 2);

	sort_test(stack_a, stack_b);

	printf("\n");			// Formating

	debug_print_stacks(stack_a, stack_b, 2);

	printf("\n");			// Formating
}

/*
	ss(stack_a, stack_b, 0);
	ss(stack_a, stack_b, 1);
	ss(stack_a, stack_b, 2);

	pp(stack_a, stack_b, 1);
	pp(stack_a, stack_b, 0);

	rr(stack_a, stack_b, 0);
	rr(stack_a, stack_b, 1);
	rr(stack_a, stack_b, 2);

	rrr(stack_a, stack_b, 0);
	rrr(stack_a, stack_b, 1);
	rrr(stack_a, stack_b, 2);
*/

void	prints_random(int n)
{
	int	*array;
	int	temp;
	int	i;
	int	j;

	i = -1;
	array = ft_calloc(n + 1, sizeof(int));
	while (++i < n)
		array[i] = i + 1;
    if (n > 1) 
    {
        i = -1;
        while (++i < n - 1) 
        {
          j = i + rand() / (RAND_MAX / (n - i) + 1);
          temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        }
    }
	i = -1;
	printf("\nNew list :");
	while (++i < n)
		printf(" %i", array[i]);
}

// 1 15 77 48 56 26 11 71 8 95 45 58 86 17 19 61 73 18 50 25 54 76 68 10 89 65 33 75 12 79 94 84 2 37 83 57 3 85 100 62 55 99 32 13 81 49 7 31 63 72 20 28 64 66 9 46 78 96 97 40 59 47 82 52 39 35 22 70 42 27 44 21 80 98 88 87 69 30 24 29 16 43 23 36 74 5 60 67 6 34 93 4 41 53 38 51 91 14 90 92
