/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:30:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/13 12:30:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_normal_case(void)
{
	char	*s1 = "  Hello World  ";
	char	*set = " ";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "Hello World") != 0)
		printf("[FAIL] test_normal_case: expected 'Hello World', got '%s'\n", result);
	else
		printf("[PASS] test_normal_case\n");
	free(result);
}

void	test_multiple_chars_in_set(void)
{
	char	*s1 = "\t\nHello World\t\n";
	char	*set = "\t\n";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "Hello World") != 0)
		printf("[FAIL] test_multiple_chars_in_set: expected 'Hello World', got '%s'\n", result);
	else
		printf("[PASS] test_multiple_chars_in_set\n");
	free(result);
}

void	test_empty_string(void)
{
	char	*s1 = "";
	char	*set = " \t\n";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "") != 0)
		printf("[FAIL] test_empty_string: expected empty string, got '%s'\n", result);
	else
		printf("[PASS] test_empty_string\n");
	free(result);
}

void	test_only_trim_chars(void)
{
	char	*s1 = "   \t\n   ";
	char	*set = " \t\n";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "") != 0)
		printf("[FAIL] test_only_trim_chars: expected empty string, got '%s'\n", result);
	else
		printf("[PASS] test_only_trim_chars\n");
	free(result);
}

void	test_trim_inner_chars(void)
{
	char	*s1 = "  Hello  World  ";
	char	*set = " ";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "Hello  World") != 0)
		printf("[FAIL] test_trim_inner_chars: expected 'Hello  World', got '%s'\n", result);
	else
		printf("[PASS] test_trim_inner_chars\n");
	free(result);
}

void	test_empty_set(void)
{
	char	*s1 = "  Hello World  ";
	char	*set = "";
	char	*result;
	
	result = ft_strtrim(s1, set);
	if (strcmp(result, "  Hello World  ") != 0)
		printf("[FAIL] test_empty_set: expected '  Hello World  ', got '%s'\n", result);
	else
		printf("[PASS] test_empty_set\n");
	free(result);
}

int	main(void)
{
	test_normal_case();
	test_multiple_chars_in_set();
	test_empty_string();
	test_only_trim_chars();
	test_trim_inner_chars();
	test_empty_set();
	return (0);
}
