/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 09:38:08 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stacks(struct s_stack *stack_a, struct s_stack *stack_b, int type)
{
	int	i;

	if (type == 0 || type == 2)			// Type : (0)/(2) = a
	{									// Prints the A stack
		printf("\n\n -A- : ");					
		i = -1;
		while (++i < (*stack_a).max_lenght)
			printf("%i ", (*stack_a).list[i]);
		printf("\n Pos : ");
		i = -1;
		while (++i < (*stack_a).pos)
			printf("  ");
		printf("^\n Len : %i of %i\n", (*stack_a).lenght, (*stack_a).max_lenght);
	}
	if (type == 1 || type == 2)			// Type : (1)/(2) = b
	{									// Prints the B stack
		printf("\n -B- : ");
		i = -1;
		while (++i < (*stack_b).max_lenght)
			printf("%i ", (*stack_b).list[i]);
		printf("\n Pos : ");
		i = -1;
		while (++i < (*stack_b).pos)
			printf("  ");
		printf("^\n Len : %i of %i\n", (*stack_b).lenght, (*stack_b).max_lenght);
	}

}

void	debug_print_str(char **list, int len, char *name)
{							// Prints a list of strings
	int	i;
	
	printf("\n%s : ", name);
	i = -1;
	while (++i < len)
		printf("%s ", list[i]);
}

void	debug_print_int(int *list, int len, char *name)
{							// Prints a list of ints
	int	i;
	
	printf("\n%s : ", name);
	i = -1;
	while (++i < len)
		printf("%i ", list[i]);
}

void	debug_moves(struct s_stack *stack_a, struct s_stack *stack_b)
{							// Tests the moves (and the mover)
	printf("\n");			// Formating

	pp(stack_a, stack_b, 0);
	ss(stack_a, stack_b, 2);

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