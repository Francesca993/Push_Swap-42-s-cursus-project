/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:22:44 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 18:26:06 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *stack_a;

    stack_a = ft_process(argc, argv);
    if (!stack_a)
        error_exit("Err: stack A creation failed.\n");
    ft_printf("Stack A inizializzato:\n");
    print_stack(stack_a);
    free_stack(stack_a);
    return (0);
}