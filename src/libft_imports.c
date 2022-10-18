/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_imports.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:42:12 by llord             #+#    #+#             */
/*   Updated: 2022/10/18 14:06:33 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		number *= 10;
		number += (str[i] - '0');
		i++;
	}
	return ((sign * number));
}

static void	*ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = 0;
	return (s);
}

void	*ft_calloc(size_t count, size_t	size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	if (i == 0)
		i++;
	ptr = (void *)malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}
