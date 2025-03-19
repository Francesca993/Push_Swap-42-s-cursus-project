/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:21:37 by francesca         #+#    #+#             */
/*   Updated: 2025/03/19 09:27:29 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funzione Bubble Sort 
// Spiegazione:
// Ciclo while esterno (i < n - 1): Simula il ciclo principale del Bubble Sort.
// Ciclo while interno (j < n - i - 1): Confronta e scambia gli elementi adiacenti.
// Flag swapped: Se dopo un'interazione non ci sono stati scambi, 
//l'array è già ordinato e si interrompe l'ordinamento.
int	*bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
