/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
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

void	test_memcpy_normal(void)
{
	char	src[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	void	*ret1;

	// Initialize destination buffers
	ft_bzero(dest1, 20);
	ft_bzero(dest2, 20);
	
	// Copy 13 bytes from src to destinations
	ret1 = ft_memcpy(dest1, src, 13);
	memcpy(dest2, src, 13);
	
	// Verify results are correct
	if (memcmp(dest1, dest2, 20) != 0 || ret1 != dest1)
	{
		printf("[FAIL] test_memcpy_normal\n");
	}
	else
	{
		printf("[PASS] test_memcpy_normal\n");
	}
}

void	test_memcpy_zero_length(void)
{
	char	src[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	
	// Initialize destination buffers with a pattern
	memset(dest1, 'A', 20);
	memset(dest2, 'A', 20);
	
	// Copy 0 bytes from src to destinations
	ft_memcpy(dest1, src, 0);
	memcpy(dest2, src, (size_t)0); // Explicit cast to avoid warning
	
	// Verify results are correct (should remain unchanged)
	if (memcmp(dest1, dest2, 20) != 0)
	{
		printf("[FAIL] test_memcpy_zero_length\n");
	}
	else
	{
		printf("[PASS] test_memcpy_zero_length\n");
	}
}

void	test_memcpy_partial(void)
{
	char	src[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	
	// Initialize destination buffers
	ft_bzero(dest1, 20);
	ft_bzero(dest2, 20);
	
	// Copy only part of the string
	ft_memcpy(dest1, src, 5); // Only "Hello"
	memcpy(dest2, src, 5);
	
	// Verify results are correct
	if (memcmp(dest1, dest2, 20) != 0)
	{
		printf("[FAIL] test_memcpy_partial\n");
	}
	else
	{
		printf("[PASS] test_memcpy_partial\n");
	}
}

void	test_memcpy_overlap_safe(void)
{
	// Note: memcpy doesn't handle overlapping memory correctly
	// This test only checks that non-overlapping behavior matches the standard
	char	buffer1[20] = "0123456789ABCDEFGHI";
	char	buffer2[20] = "0123456789ABCDEFGHI";
	
	// Copy from one part of the buffer to another (non-overlapping)
	ft_memcpy(buffer1 + 10, buffer1, 5); // Should copy "01234" to "ABCDE"
	memcpy(buffer2 + 10, buffer2, 5);
	
	// Verify results are correct
	if (memcmp(buffer1, buffer2, 20) != 0)
	{
		printf("[FAIL] test_memcpy_overlap_safe\n");
	}
	else
	{
		printf("[PASS] test_memcpy_overlap_safe\n");
	}
}

void	test_memcpy_null(void)
{
	void	*result;
	
	// Test with NULL source and destination but size 0 (should return NULL)
	result = ft_memcpy(NULL, NULL, 0);
	
	// Verify result is NULL
	if (result != NULL)
	{
		printf("[FAIL] test_memcpy_null (expected NULL)\n");
	}
	else
	{
		printf("[PASS] test_memcpy_null\n");
	}
}

int	main(void)
{
	test_memcpy_normal();
	test_memcpy_zero_length();
	test_memcpy_partial();
	test_memcpy_overlap_safe();
	test_memcpy_null();
	return (0);
}