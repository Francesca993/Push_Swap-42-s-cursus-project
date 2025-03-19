/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:12:11 by francesca         #+#    #+#             */
/*   Updated: 2025/03/19 18:00:32 by francesca        ###   ########.fr       */
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

typedef struct s_node_data
{
    int total;
    int num_chunks;
    int node_size;
    int current_chunk;
    int pushed;
} t_node_data;


// Struttura per un nodo dello stack
typedef struct s_node {
    int value;
    struct s_node *next;
    int rank;
} t_node;

//Functions to create node
t_node  *create_node(int value);
void    add_node_back(t_node **stack, t_node *new_node);
int     stack_size(t_node *stack);
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
// Operation to sort number
void    sort_three(t_node **stack);
void    sort_five(t_node **stack_a, t_node **stack_b);
void    big_sort(t_node **stack_a, t_node **stack_b, int size);
//Algoritms
int     *bubble_sort(int *array, int size);
//Function helpers to sort number
int     find_min(t_node *stack);
void    assign_rank(t_node *stack, int *array, int size);
int     *created_sorted_array(t_node *stack, int size);
void    push_to_stack_b(t_node **a, t_node **b, int group_size);
void    bring_to_pop(t_node **stack, int position);
int     find_max_position(t_node *stack);
void    restore_from_stack_b(t_node **a, t_node **b);


#endif