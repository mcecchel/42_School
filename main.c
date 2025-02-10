/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:54:50 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 14:29:18 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	size = ac - 1;
	stack_a = stack_initialize(av + 1, size);
	stack_b = NULL;
	if (check_sorted(stack_a))
		return (0);
	sort_general(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
