/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solrac97gr <solrac97gr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:04 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/30 23:13:52 by solrac97gr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_equal_strings(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello";
	s2 = "Hello";
	n = 5;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if (result == expected)
	{
		printf("[PASS] test_equal_strings\n");
	}
	else
	{
		printf("[FAIL] test_equal_strings: expected %d, got %d\n",
			expected, result);
	}
}

void	test_different_strings(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello";
	s2 = "World";
	n = 5;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if ((result < 0 && expected < 0) || (result > 0 && expected > 0)
		|| (result == 0 && expected == 0))
	{
		printf("[PASS] test_different_strings\n");
	}
	else
	{
		printf("[FAIL] test_different_strings: expected %d, got %d\n",
			expected, result);
	}
}

void	test_partial_comparison(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello";
	s2 = "Helpful";
	n = 3;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if ((result < 0 && expected < 0) || (result > 0 && expected > 0)
		|| (result == 0 && expected == 0))
	{
		printf("[PASS] test_partial_comparison\n");
	}
	else
	{
		printf("[FAIL] test_partial_comparison: expected %d, got %d\n",
			expected, result);
	}
}

void	test_empty_strings(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "";
	s2 = "";
	n = 5;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if (result == expected)
	{
		printf("[PASS] test_empty_strings\n");
	}
	else
	{
		printf("[FAIL] test_empty_strings: expected %d, got %d\n",
			expected, result);
	}
}

void	test_one_empty_string(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello";
	s2 = "";
	n = 5;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if ((result < 0 && expected < 0) || (result > 0 && expected > 0)
		|| (result == 0 && expected == 0))
	{
		printf("[PASS] test_one_empty_string\n");
	}
	else
	{
		printf("[FAIL] test_one_empty_string: expected %d, got %d\n",
			expected, result);
	}
}

void	test_zero_size(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello";
	s2 = "World";
	n = 0;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if (result == expected)
	{
		printf("[PASS] test_zero_size\n");
	}
	else
	{
		printf("[FAIL] test_zero_size: expected %d, got %d\n",
			expected, result);
	}
}

void	test_special_characters(void)
{
	char	*s1;
	char	*s2;
	int		n;
	int		result;
	int		expected;

	s1 = "Hello\200";
	s2 = "Hello\0";
	n = 6;
	result = ft_strncmp(s1, s2, n);
	expected = strncmp(s1, s2, n);
	if ((result < 0 && expected < 0) || (result > 0 && expected > 0)
		|| (result == 0 && expected == 0))
	{
		printf("[PASS] test_special_characters\n");
	}
	else
	{
		printf("[FAIL] test_special_characters: expected %d, got %d\n",
			expected, result);
	}
}

int	main(void)
{
	test_equal_strings();
	test_different_strings();
	test_partial_comparison();
	test_empty_strings();
	test_one_empty_string();
	test_zero_size();
	test_special_characters();
	return (0);
}