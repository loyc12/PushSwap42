/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:01 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 15:19:06 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>		// For printf(?)
#include <unistd.h>

// struct def
typedef struct	s_bank
{
	int	*list;
	int	pos;
	int	lenght;
	int	max_lenght;
}		t_bank;

struct s_bank	*bank_pointer;

// From debug_tests										REMOVE BEFORE CLOSING
void	debug_print_banks(struct s_bank *bank_a, struct s_bank *bank_b, int type);
void	debug_print_str(char **list, int len, char *name);
void	debug_print_int(int*list, int len, char *name);
void	debug_moves(struct s_bank *bank_a, struct s_bank *bank_b);

// From libft_imports
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

// From filter / lister / indexer
int	format_filter(int argc, char **argv);
int value_filter(int *list, int len);
int	*lister(int argc, char **argv, int *list);
int	*indexer(int *list, int len);

// From banker
struct s_bank	banker_a(int *list);
struct s_bank	banker_b(int lenght);

// From mover
void	push(struct s_bank *src_bank, struct s_bank *dst_bank);
void	swap(struct s_bank *bank);
void	rotate(struct s_bank *bank, int type);

// From moves
void	ss(struct s_bank *bank_a, struct s_bank *bank_b, int type);
void	pp(struct s_bank *bank_a, struct s_bank *bank_b, int type);
void	rr(struct s_bank *bank_a, struct s_bank *bank_b, int type);
void	rrr(struct s_bank *bank_a, struct s_bank *bank_b, int type);

#endif