/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:35:25 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/19 18:13:03 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creiamo un array ordinato e assegniamo i rank
// Creiamo un Nodo Temporaneo (temp)
// cosi  Evitiamo di Perdere il Puntatore alla Testa dello Stack
// Se invece modificassimo direttamente stack, potremmo perdere il riferimento iniziale
// Alla fine del ciclo, stack sarebbe NULL, e non potremmo più accedere ai suoi dati.
int     *created_sorted_array(t_node *stack, int size)
{
    int     *array;
    int     i;
    t_node  *temp;

    i = 0;
    temp = stack;
    array = (int *)malloc(sizeof(int) * size);
    if (!array)
        return (NULL);
    while (temp)
    {
        array[i++] = temp->value;
        temp = temp->next;
    }
    bubble_sort(array, size);
    return (array);
}
//Assegnamo il rank
//Scorriamo ogni nodo dello stack,
//scorrismoa tutto l'array finche non troviamo il valore del nodo
// quando il value di stack è == all'array
// assegnamo il rank e incrementiamo i per scorrere l'array
//passiamo al nodo successivo
void    assign_rank(t_node *stack, int *array, int size)
{
    t_node  *temp;
    int     i;
    
    temp = stack;
    while (temp)
    {
        i = 0;
        while (i < size)
        {
            if (temp->value == array[i])
            {
                temp->rank = i;
                break;
            }
            i++;
        }
        temp = temp->next;
    }
}

#include "push_swap.h"

/* Inizializza i dati per la gestione degli igroups */
t_node_data init_igroup_data(int total)
{
    t_node_data data;

    data.total = total;
    data.num_chunks = (total <= 100) ? 5 : 11; // Suddivisione in gruppi
    data.node_size = total / data.num_chunks;
    data.current_chunk = 1;
    data.pushed = 0;
    return data;
}

/* Ottieni il limite superiore dell'igroup corrente */
int get_igroup_boundary(t_node_data *data)
{
    return data->current_chunk * data->node_size;
}

/* Muove un numero da `stack_a` a `stack_b` nella posizione migliore */
void move_to_b(t_node **a, t_node **b, int middle_igroup)
{
    if ((*a)->rank <= middle_igroup)
    {
        pb(b, a);
        if (*b && (*b)->next)
            rb(b); // Mantiene equilibrio in `stack_b`
    }
    else
    {
        pb(b, a);
    }
}

/* Sposta i numeri da `stack_a` a `stack_b` in base agli igroups */
void push_to_stack_b(t_node **a, t_node **b, int total)
{
    t_node_data data;
    int igroup_boundary;
    int middle_igroup;

    data = init_igroup_data(total);
    while (*a)
    {
        igroup_boundary = get_igroup_boundary(&data);
        middle_igroup = igroup_boundary - data.node_size / 2;

        if ((*a)->rank <= igroup_boundary)
        {
            move_to_b(a, b, middle_igroup);
            data.pushed++;
        }
        else
            ra(a);

        if (data.pushed == igroup_boundary)
            data.current_chunk++;
    }
}

/* Trova la posizione del valore massimo in `stack_b` */
int find_max_position(t_node *b)
{
    int max_value = b->rank;
    int max_pos = 0;
    int i = 0;
    t_node *temp = b;

    while (temp)
    {
        if (temp->rank > max_value)
        {
            max_value = temp->rank;
            max_pos = i;
        }
        temp = temp->next;
        i++;
    }
    return max_pos;
}

/* Porta in cima il valore massimo in `stack_b` */
void bring_to_top(t_node **b, int position)
{
    int b_len = stack_size(*b);
    int steps;

    if (position <= b_len / 2)
    {
        while (position-- > 0)
            rb(b);
    }
    else
    {
        steps = b_len - position;
        while (steps-- > 0)
            rrb(b);
    }
}

/* Ripristina i numeri da `stack_b` a `stack_a` in ordine decrescente */
void restore_from_stack_b(t_node **a, t_node **b)
{
    int max_pos;

    while (*b)
    {
        max_pos = find_max_position(*b);
        bring_to_top(b, max_pos);
        pa(a, b);
    }
}

void big_sort(t_node **stack_a, t_node **stack_b, int size)
{
    int *sorted_array;

    sorted_array = created_sorted_array(*stack_a, size);
    assign_rank(*stack_a, sorted_array, size);
    free(sorted_array);

    push_to_stack_b(stack_a, stack_b, size);
    restore_from_stack_b(stack_a, stack_b);
}
