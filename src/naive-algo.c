/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_than_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:19:56 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 20:16:48 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "stdio.h"

int	check_list_a(t_stack *stack_a)
{
	t_node	*temp;

	temp = stack_a->top;
	while (temp->next != NULL)
	{
		if (temp->data <= temp->next->data)
			temp = temp->next;
		else
		{
			return (1);
		}
	}
	return (0);
}

int	check_list_b(t_stack *stack_b)
{
	t_node	*temp;

	temp = stack_b->top;
	while (temp->next != NULL)
	{
		if (temp->data >= temp->next->data)
			temp = temp->next;
		else
		{
			return (1);
		}
	}
	return (0);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	while (check_list_b(stack_b) != 0)
	{
		if (stack_b->top->data < stack_b->bottom->data)
			rotate_stack(stack_b, 'b');
		if (stack_b->top->data < stack_b->top->next->data)
			swap_stack(stack_b, 'b');
		if (stack_b->top->data >= stack_b->bottom->data && \
				stack_b->top->data >= stack_b->top->next->data)
			push_stack(stack_b, stack_a, 'b');
	}
}

void	ft_naive_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	while (check_list_a(stack_a) != 0)
	{
		if (stack_a->top->data > stack_a->bottom->data)
			rotate_stack(stack_a, 'a');
		if (stack_a->top->data > stack_a->top->next->data)
			swap_stack(stack_a, 'a');
		if (stack_a->top->data <= stack_a->bottom->data && \
				stack_a->top->data <= stack_a->top->next->data)
		{
			push_stack(stack_a, stack_b, 'a');
			sort_b(stack_a, stack_b);
		}
	}
	temp = stack_b->top;
	while (temp != NULL)
	{
		push_stack(stack_b, stack_a, 'b');
		temp = stack_b->top;
	}
}
