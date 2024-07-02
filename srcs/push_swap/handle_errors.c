/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:51:41 by abakirca          #+#    #+#             */
/*   Updated: 2024/04/26 14:21:26 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	zero_check(char *str_n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	while (str_n[i] == '0')
		i++;
	while (str_n[i + j])
		j++;
	if (j > 11)
		return (1);
	else
		return (0);
}

int	error_syntax(char *str_n)
{
	if (zero_check(str_n))
		return (1);
	if (!(*str_n == '+' || *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a, char **args, int flag)
{
	if (flag)
		destroy_args(args);
	free_stack(a);
	put_error();
}
