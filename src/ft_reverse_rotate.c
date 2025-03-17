/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:56:58 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 17:06:35 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Reverse rotate -> l ultimo elemento diventa il primo
void    reverse_rotate(t_list **stack)
{
    t_list  *prev;
    t_list  *last;

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
void    rra(t_list **a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

void    rrb(t_list **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}
void    rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}