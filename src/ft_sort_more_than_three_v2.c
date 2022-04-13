/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_than_three_v2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:44:49 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/12 22:28:38 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stdio.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int		middle;
	int		ra_count;
	int		pb_count;
	int		count;

	middle = mid(stack_a);
	ra_count = 0;
	pb_count = 0;
	count = 0;

	if (len == 2)
	{
		sort_a_two(stack_a);
		return ;
	}
	while (count < len)
	{
		if (stack_a->top->data > middle)
		{
			rotate_stack(stack_a, 'a');
			ra_count++;
		}
		else
		{
			push_stack(stack_a, stack_b, 'a');
			pb_count++;
		}
		count++;
	}
	count = 0;
	while (count < ra_count)
	{
		reverse_rotate(stack_a, 'a');
		count++;
	}
	a_to_b(stack_a, stack_b, ra_count);
	b_to_a(stack_b, stack_a, pb_count);
}

void	b_to_a(t_stack *stack_b, t_stack *stack_a, int len)
{
	int		middle;
	int		rb_count;
	int		pa_count;
	int		count;

	middle = mid(stack_b);
	rb_count = 0;
	pa_count = 0;
	count = 0;

	if (len == 1)
	{
		push_stack(stack_b, stack_a, 'b');
		return ;
	}
	if (len == 2)
	{
		sort_b_two(stack_a, stack_b);
		return ;
	}
	while (count < len)
	{
		if (stack_b->top->data < middle)
		{
			rotate_stack(stack_b, 'b');
			rb_count++;
		}
		else
		{
			push_stack(stack_b, stack_a, 'b');
			pa_count++;
		}
		count++;
	}
	count = 0;
	while (count < rb_count)
	{
		reverse_rotate(stack_b, 'b');
		count++;
	}
	a_to_b(stack_a, stack_b, pa_count);
	b_to_a(stack_b, stack_a, rb_count);
}
