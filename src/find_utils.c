/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:18 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 16:55:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_average(t_list *stack_b)
{
	t_list	*tmp;
	int		elem_sum;
	int		elem_count;

	if (stack_b == NULL)
		return (0);
	tmp = stack_b;
	elem_sum = 0;
	elem_count = 0;
	while (tmp)
	{
		elem_sum += tmp->content;
		elem_count++;
		tmp = tmp->next;
	}
	if (elem_count == 0)
		return (0);
	return (elem_sum / elem_count);
}

int	find_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->content == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	find_best_node(t_list *stack_a, t_list *stack_b, t_list *current_b)
{
	t_list	*tmp;
	t_list	*best_node;
	bool	best_match;

	tmp = stack_a;
	best_match = false;
	while (tmp)
	{
		if ((tmp->content > current_b->content) && (best_match == false
				|| tmp->content < best_node->content))
		{
			best_match = true;
			best_node = tmp;
		}
		tmp = tmp->next;
	}
	if (best_match == false)
	{
		best_node = find_min(stack_a);
	}
	current_b->moves.target = best_node;
	count_moves(stack_a, stack_b, current_b);
}

t_list	*find_cheapest_node(t_list *stack)
{
	t_list	*tmp;
	t_list	*cheapest_node;
	bool	cheapest_match;

	tmp = stack;
	cheapest_match = false;
	while (tmp)
	{
		if (cheapest_match == false || tmp->moves.total_rotations
			< cheapest_node->moves.total_rotations)
		{
			cheapest_match = true;
			cheapest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest_node);
}

void	find_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;	
	int		a_size;
	int		b_size;

	a_size = list_size(stack_a);
	b_size = list_size(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		tmp->moves.total_rotations = INT_MAX;
		find_best_node(stack_a, stack_b, tmp);
		tmp = tmp->next;
	}
}
