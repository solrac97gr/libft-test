/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:50:52 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/25 21:18:09 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_if_a_is_found_return_pointer_to_position(void)
{
	char	s[5] = {1, 2, 3, 4, '\0'};
	char	*result;
	char	*expected;

	result = ft_strchr(s, 3);
	expected = strchr(s, 3);
	if (result != expected)
	{
		printf("[FAIL] if_a_is_found_return_pointer_to_position\n");
	}
	else
	{
		printf("[PASS] if_a_is_found_return_pointer_to_position\n");
	}
}

void	test_if_x_is_not_found_return_pointer_to_null(void)
{
	char	s[5] = {1, 2, 3, 4, '\0'};
	char	*result;
	char	*expected;

	result = ft_strchr(s, 9);
	expected = strchr(s, 9);
	if (result != expected)
	{
		printf("[FAIL] test_if_x_is_not_found_return_pointer_to_null\n");
	}
	else
	{
		printf("[PASS] test_if_x_is_not_found_return_pointer_to_null\n");
	}
}

void	test_if_char_is_null_return_pointer_to_null_terminator(void)
{
	char	s[] = "Hello";
	char	*result;
	char	*expected;

	result = ft_strchr(s, '\0');
	expected = strchr(s, '\0');
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

void	test_if_char_is_found_multiple_times_return_first_occurrence(void)
{
	char	s[] = "Hello World";
	char	*result;
	char	*expected;

	result = ft_strchr(s, 'l');
	expected = strchr(s, 'l');
	if (result != expected)
	{
		printf("[FAIL] test_if_char_is_found_multiple_times_return_first_occurrence\n");
		printf("       Got: %p, Expected: %p\n", (void *)result, (void *)expected);
	}
	else
	{
		printf("[PASS] test_if_char_is_found_multiple_times_return_first_occurrence\n");
	}
}

void	test_empty_string_with_null_char(void)
{
	char	s[] = "";
	char	*result;
	char	*expected;

	result = ft_strchr(s, '\0');
	expected = strchr(s, '\0');
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

int	main(void)
{
	test_if_a_is_found_return_pointer_to_position();
	test_if_x_is_not_found_return_pointer_to_null();
	test_if_char_is_null_return_pointer_to_null_terminator();
	test_if_char_is_found_multiple_times_return_first_occurrence();
	test_empty_string_with_null_char();
	return (0);
}