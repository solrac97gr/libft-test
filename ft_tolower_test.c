/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:05:20 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/24 20:05:20 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	test_uppercase_to_lowercase(void)
{
	int	result;
	int	expected;

	result = ft_tolower('A');
	expected = tolower('A');
	if (result != expected)
	{
		printf("[FAIL] test_uppercase_to_lowercase: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_uppercase_to_lowercase\n");
	}
}

void	test_lowercase_remains_unchanged(void)
{
	int	result;
	int	expected;

	result = ft_tolower('z');
	expected = tolower('z');
	if (result != expected)
	{
		printf("[FAIL] test_lowercase_remains_unchanged: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_lowercase_remains_unchanged\n");
	}
}

void	test_non_alpha_remains_unchanged(void)
{
	int	result;
	int	expected;

	result = ft_tolower('5');
	expected = tolower('5');
	if (result != expected)
	{
		printf("[FAIL] test_non_alpha_remains_unchanged: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_non_alpha_remains_unchanged\n");
	}
}

void	test_special_chars_unchanged(void)
{
	int	result;
	int	expected;

	result = ft_tolower('!');
	expected = tolower('!');
	if (result != expected)
	{
		printf("[FAIL] test_special_chars_unchanged: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_special_chars_unchanged\n");
	}
}

int	main(void)
{
	test_uppercase_to_lowercase();
	test_lowercase_remains_unchanged();
	test_non_alpha_remains_unchanged();
	test_special_chars_unchanged();
	return (0);
}