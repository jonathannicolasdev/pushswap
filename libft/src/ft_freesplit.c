/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:46:50 by jnicolas          #+#    #+#             */
/*   Updated: 2022/03/07 18:42:02 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_freesplit(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[j])
		j++;
	while (i < j)
		free(args[i++]);
	free(args);
}
