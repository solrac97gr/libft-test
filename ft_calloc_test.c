/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:40:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/06 20:40:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void	test_normal_allocation(void)
{
	int		*arr1;
	int		*arr2;
	int		i;
	int		size;
	int		result;

	size = 10;
	arr1 = (int *)ft_calloc(size, sizeof(int));
	arr2 = (int *)calloc(size, sizeof(int));
	
	if (!arr1 || !arr2)
	{
		printf("[FAIL] test_normal_allocation: allocation failed\n");
		if (arr1)
			free(arr1);
		if (arr2)
			free(arr2);
		return ;
	}
	
	result = memcmp(arr1, arr2, size * sizeof(int));
	
	// Additional check to verify all elements are zero
	i = 0;
	while (i < size && arr1[i] == 0)
		i++;
	
	if (result != 0 || i != size)
	{
		printf("[FAIL] test_normal_allocation: memory not zeroed properly\n");
	}
	else
	{
		printf("[PASS] test_normal_allocation\n");
	}
	
	free(arr1);
	free(arr2);
}

void	test_zero_size(void)
{
	char	*ptr1;
	char	*ptr2;
	int		result;

	ptr1 = (char *)ft_calloc(0, sizeof(char));
	ptr2 = (char *)calloc(0, sizeof(char));
	
	// Both should return valid pointers even for zero size
	// But we can't really check the content
	result = (ptr1 != NULL) == (ptr2 != NULL);
	
	if (!result)
	{
		printf("[FAIL] test_zero_size: one returned NULL, the other didn't\n");
	}
	else
	{
		printf("[PASS] test_zero_size\n");
	}
	
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
}

void	test_zero_count(void)
{
	char	*ptr1;
	char	*ptr2;
	int		result;

	ptr1 = (char *)ft_calloc(10, 0);
	ptr2 = (char *)calloc(10, 0);
	
	// Both should return valid pointers even for zero size
	result = (ptr1 != NULL) == (ptr2 != NULL);
	
	if (!result)
	{
		printf("[FAIL] test_zero_count: one returned NULL, the other didn't\n");
	}
	else
	{
		printf("[PASS] test_zero_count\n");
	}
	
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
}

void	test_large_allocation(void)
{
	char	*ptr1;
	char	*ptr2;
	size_t	size;
	int		i;
	int		result;

	size = 1024 * 1024; // 1MB
	ptr1 = (char *)ft_calloc(1, size);
	ptr2 = (char *)calloc(1, size);
	
	if (!ptr1 || !ptr2)
	{
		printf("[FAIL] test_large_allocation: allocation failed\n");
		if (ptr1)
			free(ptr1);
		if (ptr2)
			free(ptr2);
		return ;
	}
	
	// Check first few bytes
	result = memcmp(ptr1, ptr2, 100);
	
	// Additional check
	i = 0;
	while (i < 100 && ptr1[i] == 0)
		i++;
	
	if (result != 0 || i != 100)
	{
		printf("[FAIL] test_large_allocation: memory not zeroed properly\n");
	}
	else
	{
		printf("[PASS] test_large_allocation\n");
	}
	
	free(ptr1);
	free(ptr2);
}

void	test_multiple_types(void)
{
	int		*int_arr;
	double	*double_arr;
	char	*char_arr;
	int		i;
	int		int_size;
	int		double_size;
	int		char_size;

	int_size = 5;
	double_size = 3;
	char_size = 10;
	
	int_arr = (int *)ft_calloc(int_size, sizeof(int));
	double_arr = (double *)ft_calloc(double_size, sizeof(double));
	char_arr = (char *)ft_calloc(char_size, sizeof(char));
	
	if (!int_arr || !double_arr || !char_arr)
	{
		printf("[FAIL] test_multiple_types: allocation failed\n");
		if (int_arr)
			free(int_arr);
		if (double_arr)
			free(double_arr);
		if (char_arr)
			free(char_arr);
		return ;
	}
	
	// Check if all elements are zeroed
	i = 0;
	while (i < int_size && int_arr[i] == 0)
		i++;
	
	if (i != int_size)
	{
		printf("[FAIL] test_multiple_types: int array not zeroed properly\n");
		free(int_arr);
		free(double_arr);
		free(char_arr);
		return ;
	}
	
	i = 0;
	while (i < double_size && double_arr[i] == 0.0)
		i++;
	
	if (i != double_size)
	{
		printf("[FAIL] test_multiple_types: double array not zeroed properly\n");
		free(int_arr);
		free(double_arr);
		free(char_arr);
		return ;
	}
	
	i = 0;
	while (i < char_size && char_arr[i] == 0)
		i++;
	
	if (i != char_size)
	{
		printf("[FAIL] test_multiple_types: char array not zeroed properly\n");
	}
	else
	{
		printf("[PASS] test_multiple_types\n");
	}
	
	free(int_arr);
	free(double_arr);
	free(char_arr);
}

void	test_size_overflow(void)
{
	void	*ptr;
	
	// Test overflow condition
	ptr = ft_calloc(SIZE_MAX, 2);
	
	if (ptr != NULL)
	{
		printf("[FAIL] test_size_overflow: should return NULL for SIZE_MAX allocation\n");
		free(ptr);
	}
	else
	{
		printf("[PASS] test_size_overflow\n");
	}
}

int	main(void)
{
	test_normal_allocation();
	test_zero_size();
	test_zero_count();
	test_large_allocation();
	test_multiple_types();
	test_size_overflow();
	return (0);
}