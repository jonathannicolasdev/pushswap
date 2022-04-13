/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:26:44 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/05 21:49:58 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	swap_stack(t_stack	*stack, int flag)
{
	t_node	*top;
	t_node	*top_next;

	if (stack->len < 2)
		return ;
	top = stack->top;
	top_next = stack->top->next;
	if (stack->len > 2)
		top_next->next->prev = top;
	top->next = top_next->next;
	top->prev = top_next;
	top_next->next = top;
	top_next->prev = NULL;
	stack->top = top_next;
	if (stack->len == 2)
		stack->bottom = top;
	if (flag == 'a')
		printf("sa\n");
	if (flag == 'b')
		printf("sb\n");
}

void	swap_all_stack(t_stack *a, t_stack *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == 'c')
		printf("ss");
}
