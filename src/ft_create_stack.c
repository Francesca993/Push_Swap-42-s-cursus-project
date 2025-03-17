/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:45:33 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 18:39:15 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_exit("Atoi failed.\n");
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		error_exit("Falls the conversion numbers\n");
	return (mod * i);
}

// Funzione per stampare lo stack usando `ft_printf`
void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", (int)(intptr_t)stack->content);
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

t_list  *init_stack_a_tostring(char *argv)
{
    t_list  *stack_a;
    t_list  *new_node;
    char    **numbers;
    int     i;
    int     num;

    i = 0;
    stack_a = NULL;

    numbers = read_input(argv);
    while (numbers[i])
    {
        num = ft_atoi2(numbers[i]); // converte la stringa in numero
        new_node = ft_lstnew((void*)(intptr_t)num);//crea un nodo con lstnew di libft
        if (!new_node)
        {
            ft_printf("Err: allocation memory failed.\n");
            free_stack(stack_a);
            return (NULL);
        }
        ft_lstadd_back(&stack_a, new_node);//aggiunge in fondo per mantenere l ordine
        free(numbers[i]);
        i++;
    }
    free (numbers);
    return (stack_a);
}

t_list  *init_stack_a_toinput(int argc, char **argv)
{
    int     i;
    t_list  *stack_a;
    t_list  *new_node;
    int     num;

    stack_a = NULL;
    i = 1;
    while (i < argc)
    {
        num = ft_atoi2(argv[i]);
        new_node = ft_lstnew((void *)(intptr_t)num);
        ft_lstadd_back(&stack_a, new_node);
        i++;
    }
    return (stack_a);
}

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string. Call
//	  another function. <init_stack_a_tostring>
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
t_list  *ft_process(int argc, char **argv)
{
    t_list  *stack_a;

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
    ft_printf("Stack A correctly inizialized.\n");
    return (stack_a);
}
