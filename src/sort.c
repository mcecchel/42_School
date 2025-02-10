/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:03:16 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/03 15:58:39 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack_a)
{
	t_list	*min;

	min = stack_a;
	if (stack_a == NULL)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->content < min->content)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (check_sorted(*stack_a))
		return ;
	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if ((first < second && first < third) || (first > second && first < third)
		|| (first > second && second > third))
		swap(*stack_a, true, true);
	if (check_sorted(*stack_a))
		return ;
	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && first > third)
		rotate(stack_a, true, true);
	else if (first < second && first > third)
		reverse_rotate(stack_a, true, true);
}

void	move_and_sort_initial(t_list **stack_a, t_list **stack_b)
{
	int	average;

	while (list_size(*stack_a) > 3)
	{
		average = find_average(*stack_b);
		if ((*stack_a)->content < average)
		{
			push_b(stack_a, stack_b, true);
			rotate(stack_b, false, true);
		}
		else
		{
			push_b(stack_a, stack_b, true);
		}
	}
	sort_three(stack_a);
}

void	sort_general(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	if (check_sorted(*stack_a))
		return ;
	move_and_sort_initial(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		find_cost(*stack_a, *stack_b);
		cheapest_node = find_cheapest_node(*stack_b);
		exec_moves(stack_a, stack_b, cheapest_node);
		push_a(stack_a, stack_b, true);
	}
	cheapest_node = find_min(*stack_a);
	while (*stack_a != cheapest_node)
	{
		if (find_position(*stack_a, cheapest_node->content)
			<= list_size(*stack_a) / 2 + 1)
			rotate(stack_a, true, true);
		else
			reverse_rotate(stack_a, true, true);
	}
}
