/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:11:56 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 18:20:23 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	synchro_r(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (cheapest_node->moves.a_rotations > 0
		&& cheapest_node->moves.b_rotations > 0)
	{
		rr(stack_a, stack_b, true);
		cheapest_node->moves.a_rotations--;
		cheapest_node->moves.b_rotations--;
	}
	while (cheapest_node->moves.a_rev_rotations > 0
		&& cheapest_node->moves.b_rev_rotations > 0)
	{
		rrr(stack_a, stack_b, true);
		cheapest_node->moves.a_rev_rotations--;
		cheapest_node->moves.b_rev_rotations--;
	}
}

void	individual_r(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (cheapest_node->moves.a_rotations > 0)
	{
		rotate(stack_a, true, true);
		cheapest_node->moves.a_rotations--;
	}
	while (cheapest_node->moves.b_rotations > 0)
	{
		rotate(stack_b, false, true);
		cheapest_node->moves.b_rotations--;
	}
	while (cheapest_node->moves.a_rev_rotations > 0)
	{
		reverse_rotate(stack_a, true, true);
		cheapest_node->moves.a_rev_rotations--;
	}
	while (cheapest_node->moves.b_rev_rotations > 0)
	{
		reverse_rotate(stack_b, false, true);
		cheapest_node->moves.b_rev_rotations--;
	}
}

void	exec_moves(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	synchro_r(stack_a, stack_b, cheapest_node);
	individual_r(stack_a, stack_b, cheapest_node);
}
