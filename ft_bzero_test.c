/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
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

void	test_bzero_normal(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result;

	// First fill the buffers with a known value
	memset(buffer1, 'A', 20);
	memset(buffer2, 'A', 20);

	// Apply bzero to the first 10 bytes
	ft_bzero(buffer1, 10);
	bzero(buffer2, 10);

	result = memcmp(buffer1, buffer2, 20);
	if (result != 0)
	{
		printf("[FAIL] test_bzero_normal\n");
	}
	else
	{
		printf("[PASS] test_bzero_normal\n");
	}
}

void	test_bzero_zero_length(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result;

	// Fill the buffers with a known value
	memset(buffer1, 'B', 20);
	memset(buffer2, 'B', 20);

	// Apply bzero with length 0 (shouldn't change anything)
	ft_bzero(buffer1, 0);
	bzero(buffer2, (size_t)0); // Explicit cast to avoid warning

	result = memcmp(buffer1, buffer2, 20);
	if (result != 0)
	{
		printf("[FAIL] test_bzero_zero_length\n");
	}
	else
	{
		printf("[PASS] test_bzero_zero_length\n");
	}
}

void	test_bzero_entire_buffer(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result;

	// Fill the buffers with a known value
	memset(buffer1, 'C', 20);
	memset(buffer2, 'C', 20);

	// Apply bzero to the entire buffer
	ft_bzero(buffer1, 20);
	bzero(buffer2, 20);

	result = memcmp(buffer1, buffer2, 20);
	if (result != 0)
	{
		printf("[FAIL] test_bzero_entire_buffer\n");
	}
	else
	{
		printf("[PASS] test_bzero_entire_buffer\n");
	}
}

void	test_bzero_partial_buffer(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		result1;
	int		result2;

	// Fill the buffers with a known value
	memset(buffer1, 'D', 20);
	memset(buffer2, 'D', 20);

	// Apply bzero to half of the buffer
	ft_bzero(buffer1, 10);
	bzero(buffer2, 10);

	// Verify that the first 10 bytes are the same (should be zeros)
	result1 = memcmp(buffer1, buffer2, 10);

	// Verify that the second 10 bytes are the same (should be 'D')
	result2 = memcmp(buffer1 + 10, buffer2 + 10, 10);

	if (result1 != 0 || result2 != 0)
	{
		printf("[FAIL] test_bzero_partial_buffer\n");
	}
	else
	{
		printf("[PASS] test_bzero_partial_buffer\n");
	}
}

void	test_bzero_non_char_buffer(void)
{
	int		int_buffer1[5];
	int		int_buffer2[5];
	int		i;
	int		result = 0;

	// Initialize buffers with values
	for (i = 0; i < 5; i++)
	{
		int_buffer1[i] = 42;
		int_buffer2[i] = 42;
	}

	// Apply bzero to the buffers
	ft_bzero(int_buffer1, sizeof(int) * 3); // Zero out the first 3 integers
	bzero(int_buffer2, sizeof(int) * 3);

	// Verify that the results are equal
	result = memcmp(int_buffer1, int_buffer2, sizeof(int) * 5);
	if (result != 0)
	{
		printf("[FAIL] test_bzero_non_char_buffer\n");
	}
	else
	{
		printf("[PASS] test_bzero_non_char_buffer\n");
	}
}

int	main(void)
{
	test_bzero_normal();
	test_bzero_zero_length();
	test_bzero_entire_buffer();
	test_bzero_partial_buffer();
	test_bzero_non_char_buffer();
	return (0);
}
