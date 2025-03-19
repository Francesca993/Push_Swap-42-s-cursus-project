/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:45:33 by francesca         #+#    #+#             */
/*   Updated: 2025/03/19 09:06:03 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funzione per stampare lo stack usando `ft_printf`
void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

char    **read_input(char *argv)
{
    char     **numbers;

    numbers = ft_split(argv, ' ');
    if (!numbers)
        return (NULL);
    return (numbers);

}

t_node  *init_stack_a_tostring(char *argv)
{
    t_node  *stack_a;
    t_node  *new_node;
    char    **numbers;
    int     i;
    int     num;

    i = 0;
    stack_a = NULL;

    numbers = read_input(argv);
    while (numbers[i])
    {
        num = ft_atoi2(numbers[i]); // converte la stringa in numero
        new_node = create_node(num);//crea un nodo con lstnew di libft
        if (!new_node)
        {
            ft_printf("Err: allocation memory failed.\n");
            free_stack(stack_a);
            return (NULL);
        }
        add_node_back(&stack_a, new_node);//aggiunge in fondo per mantenere l ordine
        free(numbers[i]);
        i++;
    }
    free (numbers);
    return (stack_a);
}

t_node  *init_stack_a_toinput(int argc, char **argv)
{
    int     i;
    t_node  *stack_a;
    t_node  *new_node;
    int     num;

    stack_a = NULL;
    i = 1;
    while (i < argc)
    {
        num = ft_atoi2(argv[i]);
        new_node = create_node(num);
        add_node_back(&stack_a, new_node);
        i++;
    }
    return (stack_a);
}

