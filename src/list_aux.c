/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:47:21 by mcecchel          #+#    #+#             */
/*   Updated: 2025/01/31 16:31:41 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int nbr)
{
	t_list	*new_node;
	t_list	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		error_exit("Error\n");
	new_node->content = nbr;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
	}
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

int	list_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

bool	check_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while ((current != NULL) && (current->next != NULL))
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}
