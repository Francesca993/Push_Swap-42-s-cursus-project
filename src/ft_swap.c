/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:29:43 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 16:40:05 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_list **stack)
{
    t_list  *first;
    t_list  *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = first;
    *stack = second;
}
//scambia i primi due elementi di A
void    sa(t_list **a)
{
    swap(a);
    ft_printf("sa\n");
}

//scambia i primi due elementi di B
void    sb(t_list **b)
{
    swap(b);
    ft_printf("sb\n");
}
//scambia i primi due lementi di entrambi gli stack
void    ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}