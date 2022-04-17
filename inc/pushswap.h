/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:52:58 by jnicolas          #+#    #+#             */
/*   Updated: 2022/04/16 20:32:18 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>      
# include <fcntl.h>
# include "libft.h"

# define MAXINT	214748347
# define MININT	-2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	unsigned int	len;
	t_node			*top;
	t_node			*bottom;
}	t_stack;

void	free_stack(t_stack	*stack);
t_stack	*stack_init(void);
t_node	*create_node(int nb);
void	insert_node_bottom(t_stack *stack, t_node *node);
void	show_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_all(t_stack *a, t_stack *b, int flag);
void	reverse_rotate(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);
int		ft_sort(t_stack *stack_a, t_stack *stack_b, int len);
void	ft_sort_three_a(t_stack *stack);
void	ft_naive_algo(t_stack *stack_a, t_stack *stack_b);
int		check_list_b(t_stack *stack_b);
int		check_list_a(t_stack *stack_a);
void	sort_b(t_stack *stack_a, t_stack *stack_b);
int		max(t_stack *stack, int len);
int		min(t_stack *stack, int len);
int		mid(t_stack *stack, int len);
void	a_to_b(t_stack *stack_a, t_stack *stack_b, int len);
void	b_to_a(t_stack *stack_b, t_stack *stack_a, int len);
void	sort_a_two(t_stack *stack_a);
void	sort_b_two(t_stack *stack_a, t_stack *stack_b);
#endif
