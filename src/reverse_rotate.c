/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:08:10 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 19:19:01 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	reverse_rotate(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*tmp_prev;

	if (stack->len < 2)
		return ;
	tmp = stack->bottom;
	tmp_prev = stack->bottom->prev;
	stack->top->prev = tmp;
	tmp->next = stack->top;
	tmp->prev = NULL;
	stack->top = tmp;
	stack->bottom = tmp_prev;
	stack->bottom->next = NULL;
	if (flag == 'a')
		printf("rra\n");
	if (flag == 'b')
		printf("rrb\n");
}

void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate(a, flag);
	reverse_rotate(b, flag);
	if (flag == 'c')
		printf("rrr\n");
}
