/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:12:11 by francesca         #+#    #+#             */
/*   Updated: 2025/03/18 14:49:50 by fmontini         ###   ########.fr       */
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

//Functions to create node
t_node  *create_node(int value);
void    add_node_back(t_node **stack, t_node *new_node);
//Function for exit and free
void	error_exit(const char *msg);
void    free_stack(t_node *stack);
//Function to read and create the stack
t_node  *ft_process(int argc, char **argv);
void	print_stack(t_node *stack);
int     ft_atoi2(const char *str);
char    **read_input(char *argv);
t_node  *init_stack_a_tostring(char *argv);
t_node  *init_stack_a_toinput(int argc, char **argv);
//Function to check if there are duplicate
int     is_duplicate(t_node *stack);
//Operations
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

#endif