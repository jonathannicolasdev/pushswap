/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:09:01 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/12 18:45:13 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_node *node;
	int i;
	int nb;

	stack_a = stack_init();
	stack_b = stack_init();
	i = 0;
	if (!argc)
		return (0);
	while (argv[++i] != NULL)
	{
		nb = ft_atoi(argv[i]);
		node = create_node(nb);
		insert_node_bottom(stack_a, node);
	}
	show_stack(stack_a);
	// printf("%d\n", stack_a->len);
	a_to_b(stack_a, stack_b, stack_a->len);
	show_stack(stack_a);
	// show_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}
