/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:56:58 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:40:30 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Reverse rotate -> l ultimo elemento diventa il primo
void    reverse_rotate(t_node **stack)
{
    t_node  *prev;
    t_node  *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}
void    rra(t_node **a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

void    rrb(t_node **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}
void    rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}