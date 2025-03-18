/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:22:44 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 15:10:58 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b = NULL;

    stack_a = ft_process(argc, argv);
    if (!stack_a)
        error_exit("Err: stack A creation failed.\n");
    ft_printf("Stack A inizializzato:\n");
    print_stack(stack_a);
    if (stack_size(stack_a) == 3)
        sort_three(&stack_a);
    if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
        sort_five(&stack_a, &stack_b);
    ft_printf("dopo cambi A\n");
    print_stack(stack_a);
    print_stack(stack_b);
    free_stack(stack_a);
    return (0);
}
