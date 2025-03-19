/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:22:44 by francesca         #+#    #+#             */
/*   Updated: 2025/03/19 11:56:10 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b = NULL;
    int     size;

    stack_a = ft_process(argc, argv);
    if (!stack_a)
        error_exit("Err: stack A creation failed.\n");
    size = stack_size(stack_a);
    // ft_printf("Stack A inizializzato:\n");
    // ft_printf("%d\n", size);
    // print_stack(stack_a);
    if (size == 3)
        sort_three(&stack_a);
    if (size == 4 || size == 5)
        sort_five(&stack_a, &stack_b);
    if (size > 5)
        big_sort(&stack_a, &stack_b, size);
    //print_stack(stack_a);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
