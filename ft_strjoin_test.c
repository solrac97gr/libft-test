/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/13 12:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_normal_case(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "World";
	char	*result;
	
	result = ft_strjoin(s1, s2);
	if (strcmp(result, "Hello World") != 0)
		printf("[FAIL] test_normal_case: expected 'Hello World', got '%s'\n", result);
	else
		printf("[PASS] test_normal_case\n");
	free(result);
}

void	test_empty_strings(void)
{
	char	*empty1 = "";
	char	*empty2 = "";
	char	*result;
	
	result = ft_strjoin(empty1, empty2);
	if (strcmp(result, "") != 0)
		printf("[FAIL] test_empty_strings: expected empty string, got '%s'\n", result);
	else
		printf("[PASS] test_empty_strings\n");
	free(result);
}

void	test_one_empty_string(void)
{
	char	*s1 = "Hello";
	char	*empty = "";
	char	*result;
	
	// Test with first string empty
	result = ft_strjoin(empty, s1);
	if (strcmp(result, "Hello") != 0)
		printf("[FAIL] test_one_empty_string (1): expected 'Hello', got '%s'\n", result);
	else
		printf("[PASS] test_one_empty_string (1)\n");
	free(result);
	
	// Test with second string empty
	result = ft_strjoin(s1, empty);
	if (strcmp(result, "Hello") != 0)
		printf("[FAIL] test_one_empty_string (2): expected 'Hello', got '%s'\n", result);
	else
		printf("[PASS] test_one_empty_string (2)\n");
	free(result);
}

void	test_special_characters(void)
{
	char	*s1 = "Hello\t";
	char	*s2 = "World\n";
	char	*result;
	
	result = ft_strjoin(s1, s2);
	if (strcmp(result, "Hello\tWorld\n") != 0)
		printf("[FAIL] test_special_characters: expected 'Hello\\tWorld\\n', got something else\n");
	else
		printf("[PASS] test_special_characters\n");
	free(result);
}

int	main(void)
{
	test_normal_case();
	test_empty_strings();
	test_one_empty_string();
	test_special_characters();
	return (0);
}
