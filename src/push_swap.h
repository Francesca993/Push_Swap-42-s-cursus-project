/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:12:11 by francesca         #+#    #+#             */
/*   Updated: 2025/03/17 18:30:44 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Include le librerie
# include <stdio.h>    // Per printf, perror, etc.
# include <stdlib.h>   // Per malloc, free, exit, etc.
# include <unistd.h>   // Per read, write, close, etc.
# include <fcntl.h>    // Per open()
# include "../Libft/libft.h"         // Include le funzioni della libft
# include "../Printf/ft_printf.h"         // Include le funzioni della libft

// Struttura per un nodo dello stack
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

void	error_exit(const char *msg);
void	print_stack(t_list *stack);
int     ft_atoi2(const char *str);
void    free_stack(t_list *stack);
int     is_duplicate(t_list *stack);
t_list  *ft_process(int argc, char **argv);
char    **read_input(char *argv);
t_list  *init_stack_a_tostring(char *argv);
t_list  *init_stack_a_toinput(int argc, char **argv);
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b);
void    pb(t_list **b, t_list **a);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

#endif