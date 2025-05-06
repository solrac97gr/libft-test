/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:49:53 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/24 19:49:53 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	test_lowercase_to_uppercase(void)
{
	int	result;
	int	expected;

	result = ft_toupper('a');
	expected = toupper('a');
	if (result != expected)
	{
		printf("[FAIL] test_lowercase_to_uppercase: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_lowercase_to_uppercase\n");
	}
}

void	test_uppercase_remains_unchanged(void)
{
	int	result;
	int	expected;

	result = ft_toupper('Z');
	expected = toupper('Z');
	if (result != expected)
	{
		printf("[FAIL] test_uppercase_remains_unchanged: got %c, expected %c\n",
			result, expected);
	}
	else
	{
		printf("[PASS] test_uppercase_remains_unchanged\n");
	}
}

void	test_non_alpha_remains_unchanged(void)
{
	int	result;
	int	expected;

	result = ft_toupper('5');
	expected = toupper('5');
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

	result = ft_toupper('$');
	expected = toupper('$');
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
	test_lowercase_to_uppercase();
	test_uppercase_remains_unchanged();
	test_non_alpha_remains_unchanged();
	test_special_chars_unchanged();
	return (0);
}
