/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:41:10 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/02 20:21:07 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	free_stack(t_stack	*stack)
{
	t_node	*tmp;

	while (stack->top != NULL)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
	}
	free(stack);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->len = 0;
	return (stack);
}

t_node	*create_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = NULL;
	node->data = nb;
	return (node);
}

void	insert_node_bottom(t_stack *stack, t_node *node)
{
	if (stack->bottom == NULL)
	{
		stack->bottom = node;
		stack->top = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		node->next = NULL;
		stack->bottom = node;
	}
	stack->len++;
}

void	show_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		printf("Data: %d Addr %p , Next: %p, Prev: %p\n", \
				tmp->data, tmp, tmp->next, tmp->prev);
		tmp = tmp->next;
	}
}
