/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:37:44 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/19 09:06:03 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_node **stack)
{
    int a;
    int b;
    int c;
    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    
    if ((a > b) && (b < c) && (a < c))
        sa(stack);
    else if ((a > b) && (b > c))
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

int find_min(t_node *stack)
{
    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}
//Se ci sono 4 o 5 numeri, spostiamo i più piccoli in stack_b, 
//ordiniamo i restanti con sort_three() e li rimettiamo in stack_a.
void sort_five(t_node **stack_a, t_node **stack_b)
{
    int min;

    if (stack_size(*stack_a) == 5)
    {
        min = find_min(*stack_a);
        while ((*stack_a)->value != min)
            ra(stack_a);
        pb(stack_b, stack_a);
    }

    min = find_min(*stack_a);
    while ((*stack_a)->value != min)
        ra(stack_a);
    pb(stack_b, stack_a);

    sort_three(stack_a);

    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
