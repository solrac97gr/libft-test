/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:05:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 23:05:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test_empty_string(void)
{
	const char	*str = "";
	size_t		res;
	size_t		expected;

	res = ft_strlen(str);
	expected = strlen(str);
	if (res != expected)
	{
		printf("[FAIL] test_empty_string: expected %zu, got %zu\n", expected, res);
	}
	else
	{
		printf("[PASS] test_empty_string\n");
	}
}

void	test_normal_string(void)
{
	const char	*str = "Hello, world!";
	size_t		res;
	size_t		expected;

	res = ft_strlen(str);
	expected = strlen(str);
	if (res != expected)
	{
		printf("[FAIL] test_normal_string: expected %zu, got %zu\n", expected, res);
	}
	else
	{
		printf("[PASS] test_normal_string\n");
	}
}

void	test_long_string(void)
{
	const char	*str = "This is a much longer string that should still work "
		"correctly with our ft_strlen implementation. The goal is to verify "
		"that our function can handle strings of various lengths efficiently "
		"and accurately.";
	size_t		res;
	size_t		expected;

	res = ft_strlen(str);
	expected = strlen(str);
	if (res != expected)
	{
		printf("[FAIL] test_long_string: expected %zu, got %zu\n", expected, res);
	}
	else
	{
		printf("[PASS] test_long_string\n");
	}
}

int	main(void)
{
	test_empty_string();
	test_normal_string();
	test_long_string();
	return (0);
}