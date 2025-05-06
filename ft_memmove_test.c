/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
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

void	test_memmove_normal(void)
{
	char	src[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	void	*ret1;

	// Initialize destination buffers
	ft_bzero(dest1, 20);
	ft_bzero(dest2, 20);
	
	// Copy 13 bytes from src to destinations
	ret1 = ft_memmove(dest1, src, 13);
	memmove(dest2, src, 13);
	
	// Verify results are correct
	if (memcmp(dest1, dest2, 20) != 0 || ret1 != dest1)
	{
		printf("[FAIL] test_memmove_normal\n");
	}
	else
	{
		printf("[PASS] test_memmove_normal\n");
	}
}

void	test_memmove_zero_length(void)
{
	char	src[] = "Hello, World!";
	char	dest1[20];
	char	dest2[20];
	
	// Initialize destination buffers with a pattern
	memset(dest1, 'A', 20);
	memset(dest2, 'A', 20);
	
	// Copy 0 bytes from src to destinations
	ft_memmove(dest1, src, 0);
	memmove(dest2, src, (size_t)0); // Explicit cast to avoid warning
	
	// Verify results are correct (should remain unchanged)
	if (memcmp(dest1, dest2, 20) != 0)
	{
		printf("[FAIL] test_memmove_zero_length\n");
	}
	else
	{
		printf("[PASS] test_memmove_zero_length\n");
	}
}

void	test_memmove_overlap_forward(void)
{
	char	buffer1[20] = "0123456789ABCDEFGHI";
	char	buffer2[20] = "0123456789ABCDEFGHI";
	
	// Move memory within the same buffer (overlapping, forward)
	ft_memmove(buffer1 + 5, buffer1, 10);
	memmove(buffer2 + 5, buffer2, 10);
	
	// Verify results are correct
	if (memcmp(buffer1, buffer2, 20) != 0)
	{
		printf("[FAIL] test_memmove_overlap_forward\n");
	}
	else
	{
		printf("[PASS] test_memmove_overlap_forward\n");
	}
}

void	test_memmove_overlap_backward(void)
{
	char	buffer1[20] = "0123456789ABCDEFGHI";
	char	buffer2[20] = "0123456789ABCDEFGHI";
	
	// Move memory within the same buffer (overlapping, backward)
	ft_memmove(buffer1, buffer1 + 5, 10);
	memmove(buffer2, buffer2 + 5, 10);
	
	// Verify results are correct
	if (memcmp(buffer1, buffer2, 20) != 0)
	{
		printf("[FAIL] test_memmove_overlap_backward\n");
	}
	else
	{
		printf("[PASS] test_memmove_overlap_backward\n");
	}
}

void	test_memmove_null(void)
{
	void	*result;
	
	// Test with NULL source and destination but size 0 (should return NULL)
	result = ft_memmove(NULL, NULL, 0);
	
	// Verify result is NULL
	if (result != NULL)
	{
		printf("[FAIL] test_memmove_null (expected NULL)\n");
	}
	else
	{
		printf("[PASS] test_memmove_null\n");
	}
}

int	main(void)
{
	test_memmove_normal();
	test_memmove_zero_length();
	test_memmove_overlap_forward();
	test_memmove_overlap_backward();
	test_memmove_null();
	return (0);
}