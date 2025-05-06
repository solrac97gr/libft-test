/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:35:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 23:35:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_memset_normal(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result;

	ft_memset(buffer1, 'A', 10);
	memset(buffer2, 'A', 10);
	
	result = memcmp(buffer1, buffer2, 10);
	if (result != 0)
	{
		printf("[FAIL] test_memset_normal\n");
	}
	else
	{
		printf("[PASS] test_memset_normal\n");
	}
}

void	test_memset_zero_length(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result;

	// First fill the buffers with something
	memset(buffer1, 'B', 10);
	memset(buffer2, 'B', 10);
	
	// Then call ft_memset with 0 length
	ft_memset(buffer1, 'X', 0);
	memset(buffer2, 'X', (size_t)0); // Explicitly cast to avoid warning
	
	result = memcmp(buffer1, buffer2, 10);
	if (result != 0)
	{
		printf("[FAIL] test_memset_zero_length\n");
	}
	else
	{
		printf("[PASS] test_memset_zero_length\n");
	}
}

void	test_memset_return_value(void)
{
	char	buffer[20];
	void	*return_val;

	return_val = ft_memset(buffer, 'C', 10);
	
	if (return_val != buffer)
	{
		printf("[FAIL] test_memset_return_value\n");
	}
	else
	{
		printf("[PASS] test_memset_return_value\n");
	}
}

void	test_memset_non_char_value(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		value;
	int		result;
	
	value = 300; // This will be truncated to unsigned char (300 % 256 = 44)
	ft_memset(buffer1, value, 10);
	memset(buffer2, value, 10);
	
	result = memcmp(buffer1, buffer2, 10);
	if (result != 0)
	{
		printf("[FAIL] test_memset_non_char_value\n");
	}
	else
	{
		printf("[PASS] test_memset_non_char_value\n");
	}
}

int	main(void)
{
	test_memset_normal();
	test_memset_zero_length();
	test_memset_return_value();
	test_memset_non_char_value();
	return (0);
}