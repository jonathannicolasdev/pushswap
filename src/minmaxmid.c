/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmaxmid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:07:04 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 21:10:08 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "stdio.h"

int	max(t_stack *stack, int len)
{
	t_node	*temp;
	int		max;

	temp = stack->top;
	max = MININT;
	while (temp != NULL && len--)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

int	min(t_stack *stack, int len)
{
	t_node	*temp;
	int		min;

	temp = stack->top;
	min = MAXINT;
	while (temp != NULL && len--)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	mid(t_stack *stack, int len)
{
	int	mid;

	mid = ((min(stack, len) + max(stack, len)) / 2);
	return (mid);
}
