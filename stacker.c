/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 09:37:01 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	stacker_a(int *list)
{							// Initializes the A stack
	struct s_stack	stack_a;
	int				i;

	i = 0;
	while (list[i])
		i++;
	stack_a.list = list;
	stack_a.pos = 0;
	stack_a.lenght = i;
	stack_a.max_lenght = i;
	return (stack_a);
}

struct s_stack	stacker_b(int lenght)
{							// Initializes the B stack
	struct s_stack	stack_b;
	int				*empty_list;

	empty_list = ft_calloc(lenght + 1, sizeof(int));
	stack_b.list = empty_list;
	stack_b.pos = 0;
	stack_b.lenght = 0;
	stack_b.max_lenght = lenght;
	return (stack_b);
}
