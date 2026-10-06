/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 11:39:53 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:06:53 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*filling_the_array(t_stack *stack)
{
	t_stack_node	*temp;
	int				*arr;
	int				i;

	if (!stack || !stack->top)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	temp = stack->top;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	return (arr);
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

static void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

static int	binary_search(int arr[], int target, int size)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (target < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}

void	indexing(t_stack *stack)
{
	t_stack_node	*temp;
	int				*array;
	int				array_size;

	if (!stack || !stack->top)
		return ;
	array = filling_the_array(stack);
	if (!array)
		return ;
	array_size = stack->size;
	quick_sort(array, 0, array_size - 1);
	temp = stack->top;
	while (temp)
	{
		temp->index = binary_search(array, temp->value, array_size);
		temp = temp->next;
	}
	free(array);
}
