/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:13:00 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/05 22:40:03 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	rotate_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*tmp_next;

	if (stack->len < 2)
		return ;
	tmp = stack->top;
	tmp_next = stack->top->next;
	stack->bottom->next = tmp;
	tmp->prev = stack->bottom;
	tmp->next = NULL;
	stack->bottom = tmp;
	stack->top = tmp_next;
	stack->top->prev = NULL;
	if (flag == 'a')
		printf("ra\n");
	if (flag == 'b')
		printf("rb\n");
}

void	rotate_all(t_stack *a, t_stack *b, int flag)
{
	rotate_stack(a, flag);
	rotate_stack(b, flag);
	if (flag == 'c')
		printf("rr");
}
