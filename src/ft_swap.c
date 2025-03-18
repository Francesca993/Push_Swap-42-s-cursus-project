/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:29:43 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:39:48 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}
//scambia i primi due elementi di A
void    sa(t_node **a)
{
    swap(a);
    ft_printf("sa\n");
}

//scambia i primi due elementi di B
void    sb(t_node **b)
{
    swap(b);
    ft_printf("sb\n");
}
//scambia i primi due lementi di entrambi gli stack
void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}