/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/05 15:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// BSD-specific strnstr function (not part of standard C)
#ifndef strnstr
char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
#endif

void	test_basic_functionality(void)
{
	const char	*haystack = "This is a simple test string";
	const char	*needle = "simple";
	char		*result;
	char		*expected;

	result = ft_strnstr(haystack, needle, strlen(haystack));
	expected = strnstr(haystack, needle, strlen(haystack));
	if (result != expected)
	{
		printf("[FAIL] test_basic_functionality\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_basic_functionality\n");
	}
}

void	test_empty_needle(void)
{
	const char	*haystack = "This is a test string";
	const char	*needle = "";
	char		*result;
	char		*expected;

	result = ft_strnstr(haystack, needle, strlen(haystack));
	expected = strnstr(haystack, needle, strlen(haystack));
	if (result != expected)
	{
		printf("[FAIL] test_empty_needle\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_empty_needle\n");
	}
}

void	test_needle_not_found(void)
{
	const char	*haystack = "This is a test string";
	const char	*needle = "notfound";
	char		*result;
	char		*expected;

	result = ft_strnstr(haystack, needle, strlen(haystack));
	expected = strnstr(haystack, needle, strlen(haystack));
	if (result != expected)
	{
		printf("[FAIL] test_needle_not_found\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_needle_not_found\n");
	}
}

void	test_len_too_short(void)
{
	const char	*haystack = "This is a test string";
	const char	*needle = "test";
	char		*result;
	char		*expected;
	size_t		len = 9; // Too short to find "test" which starts at index 10

	result = ft_strnstr(haystack, needle, len);
	expected = strnstr(haystack, needle, len);
	if (result != expected)
	{
		printf("[FAIL] test_len_too_short\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_len_too_short\n");
	}
}

void	test_len_partial_match(void)
{
	const char	*haystack = "This is a test string";
	const char	*needle = "test";
	char		*result;
	char		*expected;
	size_t		len = 12; // Only part of "test" fits in the len

	result = ft_strnstr(haystack, needle, len);
	expected = strnstr(haystack, needle, len);
	if (result != expected)
	{
		printf("[FAIL] test_len_partial_match\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_len_partial_match\n");
	}
}

void	test_needle_at_start(void)
{
	const char	*haystack = "Teststring with test at start";
	const char	*needle = "Test";
	char		*result;
	char		*expected;

	result = ft_strnstr(haystack, needle, strlen(haystack));
	expected = strnstr(haystack, needle, strlen(haystack));
	if (result != expected)
	{
		printf("[FAIL] test_needle_at_start\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_needle_at_start\n");
	}
}

void	test_zero_len(void)
{
	const char	*haystack = "This is a test string";
	const char	*needle = "test";
	char		*result;
	char		*expected;

	result = ft_strnstr(haystack, needle, 0);
	expected = strnstr(haystack, needle, 0);
	if (result != expected)
	{
		printf("[FAIL] test_zero_len\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_zero_len\n");
	}
}

int	main(void)
{
	test_basic_functionality();
	test_empty_needle();
	test_needle_not_found();
	test_len_too_short();
	test_len_partial_match();
	test_needle_at_start();
	test_zero_len();
	return (0);
}