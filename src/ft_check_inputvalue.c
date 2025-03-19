/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputvalue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:14:06 by francesca         #+#    #+#             */
/*   Updated: 2025/03/19 11:36:58 by francesca        ###   ########.fr       */
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

//MANCA FUNZIONE PER VEDERE SE LO STACK è ORDINATO!!

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string. Call
//	  another function. <init_stack_a_tostring>
// 3. It checks if the number of input is greater than 2.
//     If it is, it nodes the arguements.
t_node  *ft_process(int argc, char **argv)
{
    t_node  *stack_a;

    if (argc < 2)
        error_exit("Insufficents parameters.\n");
    if (argc == 2)
        stack_a = init_stack_a_tostring(argv[1]);
    else
        stack_a = init_stack_a_toinput(argc, argv);
    if (!stack_a)
        error_exit("Err: stack A creation failed.\n");
    if (is_duplicate(stack_a))
    {
        ft_printf("Error: Duplicates found in stack.\n");
        free_stack(stack_a);
        return (NULL);
    }
    //ft_printf("Stack A correctly inizialized.\n");
    return (stack_a);
}