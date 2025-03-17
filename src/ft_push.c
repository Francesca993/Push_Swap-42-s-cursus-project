/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:42:11 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 16:47:52 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sposta il primo elemento dii src in cima a dest
void    push(t_list **dest, t_list **src)
{
    t_list  *temp;
    if (!src || !*src)
        return ;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}
//esegue pa -> push su stack A
void    pa(t_list **a, t_list **b)
{
    push(a, b);
    ft_printf("pa\n");
}

//esegue pb -> push su stack B
void    pb(t_list **b, t_list **a)
{
    push(b, a);
    ft_printf("pb\n");
}