/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:49:53 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/12 22:21:18 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	push_from_len_one(t_stack *from, t_stack *to)
{
	if (to->len == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->len == 1)
		push_from_len_one(from, to);
	else
	{
		if (to->len == 0)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->len++;
	from->len--;
}

void	push_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->len == 0)
		return ;
	push(from, to);
	if (flag == 'a')
		printf("pb\n");
	if (flag == 'b')
		printf("pa\n");
}
