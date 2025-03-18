/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:22:44 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:52:47 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;

    stack_a = ft_process(argc, argv);
    if (!stack_a)
        error_exit("Err: stack A creation failed.\n");
    ft_printf("Stack A inizializzato:\n");
    print_stack(stack_a);
    free_stack(stack_a);
    return (0);
}
