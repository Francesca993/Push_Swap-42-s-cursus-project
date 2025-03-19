static void radix_sort(t_node **a, t_node **b, int size)
{
    int max_bits;
    int i, j;
    int num;

    max_bits = 0;
    while ((size - 1) >> max_bits)  
        max_bits++;  // Calcoliamo quanti bit ci servono per rappresentare tutti i numeri

    for (i = 0; i < max_bits; i++)  
    {
        j = 0;
        while (j < size)  
        {
            num = (*a)->rank;
            if ((num >> i) & 1)  // Se il bit `i` è 1, ruotiamo
                ra(a);
            else  // Se il bit `i` è 0, spostiamo in `stack_b`
                pb(b, a);
            j++;
        }

        while (*b)  
            pa(a, b);  // Riportiamo tutto in stack_a dopo ogni ciclo di bit
    }
}
// void big_sort(t_node **stack_a, t_node **stack_b, int size)
// {
//     int *sorted_array;
//     sorted_array = created_sorted_array(*stack_a, size);
//     if (!sorted_array)
//         return; // Gestione dell'errore di allocazione di memoria
//     assign_rank(*stack_a, sorted_array, size);
//     free(sorted_array);
//     radix_sort(stack_a, stack_b, size);
//     //group_sort(stack_a, stack_b, size);
// }