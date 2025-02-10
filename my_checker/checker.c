/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:57:07 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/09 14:57:33 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	error_checker(t_list **stack_a, t_list **stack_b, char *line)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(line);
	error_exit("Error\n");
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	check_command(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a, true, false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stack_b, false, false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(stack_a, true, false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(stack_b, false, false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(*stack_a, true, false);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(*stack_b, false, false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_a(stack_a, stack_b, false);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_b(stack_a, stack_b, false);
	else
		error_checker(stack_a, stack_b, line);
}

static void	exec_and_print(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line && ft_strncmp(line, "\n", 1))
	{
		check_command(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (!*stack_b && check_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	len = ac - 1;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		len = 0;
		while (av[len])
			len++;
		stack_a = stack_initialize(av, len);
		free_split(av);
	}
	else
		stack_a = stack_initialize(av + 1, len);
	stack_b = NULL;
	exec_and_print(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
