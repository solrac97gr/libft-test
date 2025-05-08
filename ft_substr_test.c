/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/09 12:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_normal_case(void)
{
	char	*str = "Hello World";
	char	*result;
	
	result = ft_substr(str, 6, 5);
	if (strcmp(result, "World") != 0)
		printf("[FAIL] test_normal_case: expected 'World', got '%s'\n", result);
	else
		printf("[PASS] test_normal_case\n");
	free(result);
}

void	test_start_beyond_end(void)
{
	char	*str = "Hello";
	char	*result;
	
	result = ft_substr(str, 10, 5);
	if (strcmp(result, "") != 0)
		printf("[FAIL] test_start_beyond_end: expected empty string, got '%s'\n", result);
	else
		printf("[PASS] test_start_beyond_end\n");
	free(result);
}

void	test_len_longer_than_string(void)
{
	char	*str = "Hello";
	char	*result;
	
	result = ft_substr(str, 0, 10);
	if (strcmp(result, "Hello") != 0)
		printf("[FAIL] test_len_longer_than_string: expected 'Hello', got '%s'\n", result);
	else
		printf("[PASS] test_len_longer_than_string\n");
	free(result);
}

void	test_zero_length(void)
{
	char	*str = "Hello";
	char	*result;
	
	result = ft_substr(str, 1, 0);
	if (strcmp(result, "") != 0)
		printf("[FAIL] test_zero_length: expected empty string, got '%s'\n", result);
	else
		printf("[PASS] test_zero_length\n");
	free(result);
}

void	test_null_string(void)
{
	char	*str = NULL;
	char	*result;
	
	result = ft_substr(str, 0, 5);
	if (result != NULL)
	{
		printf("[FAIL] test_null_string: expected NULL, got non-NULL\n");
		free(result);
	}
	else
		printf("[PASS] test_null_string\n");
}

int	main(void)
{
	test_normal_case();
	test_start_beyond_end();
	test_len_longer_than_string();
	test_zero_length();
	test_null_string();
	return (0);
}