/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:33:38 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 20:34:18 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stdio.h"

void	ft_sort_three_a(t_stack *s)
{
	if (s->top->data > s->top->next->data && s->top->data < s->bottom->data \
			&& s->top->next->data < s->bottom->data)
		swap_stack(s, 'a');
	if (s->top->data > s->top->next->data && s->top->data > s->bottom->data \
			&& s->top->next->data > s->bottom->data)
	{	
		swap_stack(s, 'a');
		reverse_rotate(s, 'a');
	}
	if (s->top->data > s->top->next->data && s->top->data > s->bottom->data \
			&& s->top->next->data < s->bottom->data)
		rotate_stack(s, 'a');
	if (s->top->data < s->top->next->data && s->top->data < s->bottom->data \
			&& s->top->next->data > s->bottom->data)
	{
		swap_stack(s, 'a');
		rotate_stack(s, 'a');
	}
	if (s->top->data < s->top->next->data && s->top->data > s->bottom->data \
			&& s->top->next->data > s->bottom->data)
		reverse_rotate(s, 'a');
}

int	ft_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 1)
		return (0);
	if (len == 2)
		swap_stack(stack_a, 'a');
	if (len == 3)
		ft_sort_three_a(stack_a);
	if (len >= 4 && len <= 10)
		ft_naive_algo(stack_a, stack_b);
	if (len > 10)
		a_to_b(stack_a, stack_b, stack_a->len);
	return (0);
}
