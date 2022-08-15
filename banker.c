/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 15:33:39 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_bank	banker_a(int *list)
{
	struct s_bank	bank_a;
	int				i;

	i = 0;
	while (list[i])
		i++;
	bank_a.list = list;
	bank_a.pos = 0;
	bank_a.lenght = i;
	bank_a.max_lenght = i;
	return (bank_a);
}

struct s_bank	banker_b(int lenght)
{
	struct s_bank	bank_b;
	int				*empty_list;
	int				i;

	empty_list = ft_calloc(lenght + 1, sizeof(int));
	bank_b.list = empty_list;
	bank_b.pos = 0;
	bank_b.lenght = 0;
	bank_b.max_lenght = lenght;
	return (bank_b);
}
