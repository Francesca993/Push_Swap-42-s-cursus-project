/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:20:13 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:41:05 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_node *stack)
{
    t_node  *temp;

    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
void	error_exit(const char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}