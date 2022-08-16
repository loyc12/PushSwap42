/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/15 12:35:03 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_banks(struct s_bank *bank_a, struct s_bank *bank_b, int type)
{								// Type: (0) = a | (1) = b | (2) = a + b
	int	i;

	if (type == 0 || type == 2)
	{
		printf("\n\n -A- : ");					// Prints bank_a
		i = -1;									//
		while (++i < (*bank_a).max_lenght)		//
			printf("%i ", (*bank_a).list[i]);	//
		printf("\n Pos : ");					//
		i = -1;									//
		while (++i < (*bank_a).pos)				//
			printf("  ");						//
		printf("^\n Len : %i of %i\n", (*bank_a).lenght, (*bank_a).max_lenght);
	}
	if (type == 1 || type == 2)
	{
		printf("\n -B- : ");			 		// Prints bank_b
		i = -1;									//
		while (++i < (*bank_b).max_lenght)		//
			printf("%i ", (*bank_b).list[i]);	//
		printf("\n Pos : ");					//
		i = -1;									//
		while (++i < (*bank_b).pos)				//
			printf("  ");						//
		printf("^\n Len : %i of %i\n", (*bank_b).lenght, (*bank_b).max_lenght);
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

void	debug_moves(struct s_bank *bank_a, struct s_bank *bank_b)
{							// Tests the moves (and the mover)
	printf("\n");			// Formating
/*
	ss(bank_a, bank_b, 0);
	ss(bank_a, bank_b, 1);
	ss(bank_a, bank_b, 2);

	pp(bank_a, bank_b, 1);
	pp(bank_a, bank_b, 0);

	rr(bank_a, bank_b, 0);
	rr(bank_a, bank_b, 1);
	rr(bank_a, bank_b, 2);

	rrr(bank_a, bank_b, 0);
	rrr(bank_a, bank_b, 1);
	rrr(bank_a, bank_b, 2);
*/
	pp(bank_a, bank_b, 0);
	ss(bank_a, bank_b, 2);

	debug_print_banks(bank_a, bank_b, 2);

	printf("\n");			// Formating
}
