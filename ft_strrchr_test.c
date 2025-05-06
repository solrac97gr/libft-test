/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/29 12:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_if_a_is_found_return_pointer_to_last_position(void)
{
	char	s[] = "Hello World";
	char	*result;
	char	*expected;

	result = ft_strrchr(s, 'l');
	expected = strrchr(s, 'l');
	if (result != expected)
	{
		printf("[FAIL] test_if_a_is_found_return_pointer_to_last_position\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_if_a_is_found_return_pointer_to_last_position\n");
	}
}

void	test_if_x_is_not_found_return_null(void)
{
	char	s[5] = {1, 2, 3, 4, '\0'};
	char	*result;
	char	*expected;

	result = ft_strrchr(s, 9);
	expected = strrchr(s, 9);
	if (result != expected)
	{
		printf("[FAIL] test_if_x_is_not_found_return_null\n");
	}
	else
	{
		printf("[PASS] test_if_x_is_not_found_return_null\n");
	}
}

void	test_if_char_is_null_return_pointer_to_null_terminator(void)
{
	char	s[] = "Hello";
	char	*result;
	char	*expected;

	result = ft_strrchr(s, '\0');
	expected = strrchr(s, '\0');
	if (result != expected)
	{
		printf("[FAIL] test_if_char_is_null_return_pointer_to_null_terminator\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_if_char_is_null_return_pointer_to_null_terminator\n");
	}
}

void	test_empty_string_with_null_char(void)
{
	char	s[] = "";
	char	*result;
	char	*expected;

	result = ft_strrchr(s, '\0');
	expected = strrchr(s, '\0');
	if (result != expected)
	{
		printf("[FAIL] test_empty_string_with_null_char\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_empty_string_with_null_char\n");
	}
}

void	test_if_char_appears_only_once(void)
{
	char	s[] = "Hello World";
	char	*result;
	char	*expected;

	result = ft_strrchr(s, 'H');
	expected = strrchr(s, 'H');
	if (result != expected)
	{
		printf("[FAIL] test_if_char_appears_only_once\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_if_char_appears_only_once\n");
	}
}

int	main(void)
{
	test_if_a_is_found_return_pointer_to_last_position();
	test_if_x_is_not_found_return_null();
	test_if_char_is_null_return_pointer_to_null_terminator();
	test_empty_string_with_null_char();
	test_if_char_appears_only_once();
	return (0);
}