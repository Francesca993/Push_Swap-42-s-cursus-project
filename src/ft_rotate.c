/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:49:08 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:40:09 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ruota lo stack e il primo elemento diventa l ultimo
void    rotate(t_node **stack)
{
    t_node  *first;
    t_node  *last;

    if(!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

//esegue rotate di a
void    ra(t_node **a)
{
    rotate(a);
    ft_printf("ra\n");
}

//esegue rotate di b
void    rb(t_node **b)
{
    rotate(b);
    ft_printf("rb\n");
}

//esegue il rotate di entrambi gli stack 
void    rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}