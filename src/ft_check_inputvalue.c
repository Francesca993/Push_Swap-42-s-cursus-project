/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputvalue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:14:06 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:46:57 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function that check if there are duplicate in stack
*/
int     is_duplicate(t_node *stack)
{
    t_node *current;
    t_node *checker;

    current = stack;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (current->value == checker->value)
                return (1); // Trovato duplicato
            checker = checker->next;
        }
        current = current->next;
    }
    return (0); // Nessun duplicato
}