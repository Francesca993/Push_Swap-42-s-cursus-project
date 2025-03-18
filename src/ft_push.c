/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:42:11 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:40:48 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sposta il primo elemento dii src in cima a dest
void    push(t_node **dest, t_node **src)
{
    t_node  *temp;
    if (!src || !*src)
        return ;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}
//esegue pa -> push su stack A
void    pa(t_node **a, t_node **b)
{
    push(a, b);
    ft_printf("pa\n");
}

//esegue pb -> push su stack B
void    pb(t_node **b, t_node **a)
{
    push(b, a);
    ft_printf("pb\n");
}