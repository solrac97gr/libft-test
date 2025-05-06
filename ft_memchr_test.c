/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solrac97gr <solrac97gr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:25:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/30 23:13:52 by solrac97gr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_basic_search(void)
{
	char	str[] = "Hello, World!";
	void	*result;
	void	*expected;

	result = ft_memchr(str, 'W', strlen(str));
	expected = memchr(str, 'W', strlen(str));
	if (result != expected)
	{
		printf("[FAIL] test_basic_search: expected %p, got %p\n", expected, result);
	}
	else
	{
		printf("[PASS] test_basic_search\n");
	}
}

void	test_char_not_found(void)
{
	char	str[] = "Hello, World!";
	void	*result;
	void	*expected;

	result = ft_memchr(str, 'Z', strlen(str));
	expected = memchr(str, 'Z', strlen(str));
	if (result != expected)
	{
		printf("[FAIL] test_char_not_found: expected %p, got %p\n", expected, result);
	}
	else
	{
		printf("[PASS] test_char_not_found\n");
	}
}

void	test_limited_range(void)
{
	char	str[] = "Hello, World!";
	void	*result;
	void	*expected;

	// Only search first 5 bytes, so 'W' should not be found
	result = ft_memchr(str, 'W', 5);
	expected = memchr(str, 'W', 5);
	if (result != expected)
	{
		printf("[FAIL] test_limited_range: expected %p, got %p\n", expected, result);
	}
	else
	{
		printf("[PASS] test_limited_range\n");
	}
}

void	test_null_byte(void)
{
	char	str[] = "Hello";
	void	*result;
	void	*expected;

	result = ft_memchr(str, '\0', 6); // Include the null terminator
	expected = memchr(str, '\0', 6);
	if (result != expected)
	{
		printf("[FAIL] test_null_byte: expected %p, got %p\n", expected, result);
	}
	else
	{
		printf("[PASS] test_null_byte\n");
	}
}

void	test_binary_data(void)
{
	unsigned char	binary[] = {0x10, 0x20, 0x30, 0x40, 0x50};
	void			*result;
	void			*expected;

	result = ft_memchr(binary, 0x30, 5);
	expected = memchr(binary, 0x30, 5);
	if (result != expected)
	{
		printf("[FAIL] test_binary_data: expected %p, got %p\n", expected, result);
	}
	else
	{
		printf("[PASS] test_binary_data\n");
	}
}

int	main(void)
{
	test_basic_search();
	test_char_not_found();
	test_limited_range();
	test_null_byte();
	test_binary_data();
	return (0);
}