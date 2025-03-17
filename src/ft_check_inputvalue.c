/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputvalue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:14:06 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 18:30:35 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_duplicate(t_list *stack)
{
    t_list *current;
    t_list *checker;

    current = stack;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if ((int)(intptr_t)current->content == (int)(intptr_t)checker->content)
                return (1); // Trovato duplicato
            checker = checker->next;
        }
        current = current->next;
    }
    return (0); // Nessun duplicato
}