/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:13:14 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/12 22:26:22 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_a_two(t_stack *stack_a)
{
	if (stack_a->top->data > stack_a->top->next->data)
		swap_stack(stack_a, 'a');
}

void	sort_b_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top->data < stack_b->top->next->data)
		swap_stack(stack_b, 'b');
	push_stack(stack_b, stack_a, 'b');
	push_stack(stack_b, stack_a, 'b');
}
