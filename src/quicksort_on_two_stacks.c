/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_than_three_v2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:44:49 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 21:33:31 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stdio.h"
int cpt_opt = 0;
int check_list_sorted_len(t_stack *stack, int len)
{
	t_node *temp;

	temp = stack->top;
	int sorted_count = 0;
	int len1 = len;
	while (temp->next != NULL && len--)
	{
		temp = temp->next;
	}
	len = len1;
	while (temp->prev != NULL && len--)
	{
		if (temp->data > temp->prev->data)
		{
			temp = temp->prev;
			sorted_count++;
		}

		else
		{

			break;
		}
	}
	if (sorted_count > 0)
	{
		sorted_count--;
		cpt_opt += sorted_count;
		// printf("cpt_opt:%d\n", cpt_opt);
	}

	return (sorted_count);
}

void a_to_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int middle;
	int ra_count;
	int pb_count;
	int count;

	int sorted_count = check_list_sorted_len(stack_a, len);
	len = len - sorted_count;

	middle = mid(stack_a, len);
	// printf("\nmiddle:%d len:%d\n", middle, len);
	// getchar();
	// getchar();
	ra_count = 0;
	pb_count = 0;
	count = 0;
	if (len == 1 || len == 0)
	{
		return;
	}
	if (len == 2)
	{
		sort_a_two(stack_a);
		return;
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
	// printf("\na--->b\n");
	// show_stack(stack_a);
	// printf("this is b a_to_b 1");
	// show_stack(stack_b);
	a_to_b(stack_a, stack_b, ra_count);

	// printf("\nb--->a\n");
	// show_stack(stack_a);
	// printf("this is b a_to_b 2\n");
	// show_stack(stack_b);
	b_to_a(stack_b, stack_a, pb_count);
}

void b_to_a(t_stack *stack_b, t_stack *stack_a, int len)
{
	int middle;
	int rb_count;
	int pa_count;
	int count;

	// test if len top elements are already in order

	middle = mid(stack_b, len);
	rb_count = 0;
	pa_count = 0;
	count = 0;
	if (len == 1 || len == 0)
	{
		push_stack(stack_b, stack_a, 'b');
		return;
	}
	if (len == 2)
	{
		sort_b_two(stack_a, stack_b);
		return;
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
