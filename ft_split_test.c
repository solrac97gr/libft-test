/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/13 17:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	test_normal_case(void)
{
	char	*str = "Hello,World,This,Is,A,Test";
	char	**result;
	int		passed = 1;
	
	result = ft_split(str, ',');
	
	if (strcmp(result[0], "Hello") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'Hello', got '%s'\n", result[0]);
		passed = 0;
	}
	if (strcmp(result[1], "World") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'World', got '%s'\n", result[1]);
		passed = 0;
	}
	if (strcmp(result[2], "This") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'This', got '%s'\n", result[2]);
		passed = 0;
	}
	if (strcmp(result[3], "Is") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'Is', got '%s'\n", result[3]);
		passed = 0;
	}
	if (strcmp(result[4], "A") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'A', got '%s'\n", result[4]);
		passed = 0;
	}
	if (strcmp(result[5], "Test") != 0)
	{
		printf("[FAIL] test_normal_case: expected 'Test', got '%s'\n", result[5]);
		passed = 0;
	}
	if (result[6] != NULL)
	{
		printf("[FAIL] test_normal_case: expected NULL terminator at index 6\n");
		passed = 0;
	}
	
	if (passed)
		printf("[PASS] test_normal_case\n");
	
	free_array(result);
}

void	test_consecutive_separators(void)
{
	char	*str = "Hello,,World";
	char	**result;
	int		passed = 1;
	
	result = ft_split(str, ',');
	
	if (strcmp(result[0], "Hello") != 0)
	{
		printf("[FAIL] test_consecutive_separators: expected 'Hello', got '%s'\n", result[0]);
		passed = 0;
	}
	if (strcmp(result[1], "World") != 0)
	{
		printf("[FAIL] test_consecutive_separators: expected 'World', got '%s'\n", result[1]);
		passed = 0;
	}
	if (result[2] != NULL)
	{
		printf("[FAIL] test_consecutive_separators: expected NULL terminator at index 2\n");
		passed = 0;
	}
	
	if (passed)
		printf("[PASS] test_consecutive_separators\n");
	
	free_array(result);
}

void	test_separators_at_ends(void)
{
	char	*str = ",Hello,World,";
	char	**result;
	int		passed = 1;
	
	result = ft_split(str, ',');
	
	if (strcmp(result[0], "Hello") != 0)
	{
		printf("[FAIL] test_separators_at_ends: expected 'Hello', got '%s'\n", result[0]);
		passed = 0;
	}
	if (strcmp(result[1], "World") != 0)
	{
		printf("[FAIL] test_separators_at_ends: expected 'World', got '%s'\n", result[1]);
		passed = 0;
	}
	if (result[2] != NULL)
	{
		printf("[FAIL] test_separators_at_ends: expected NULL terminator at index 2\n");
		passed = 0;
	}
	
	if (passed)
		printf("[PASS] test_separators_at_ends\n");
	
	free_array(result);
}

void	test_empty_string(void)
{
	char	*str = "";
	char	**result;
	
	result = ft_split(str, ',');
	
	if (result == NULL)
	{
		printf("[FAIL] test_empty_string: result is NULL\n");
	}
	else if (result[0] != NULL)
	{
		printf("[FAIL] test_empty_string: expected NULL terminator at index 0, got '%s'\n", result[0]);
		free_array(result);
	}
	else
	{
		printf("[PASS] test_empty_string\n");
		free(result);
	}
}

void	test_only_separators(void)
{
	char	*str = ",,,,,";
	char	**result;
	
	result = ft_split(str, ',');
	
	if (result == NULL)
	{
		printf("[FAIL] test_only_separators: result is NULL\n");
	}
	else if (result[0] != NULL)
	{
		printf("[FAIL] test_only_separators: expected NULL terminator at index 0, got '%s'\n", result[0]);
		free_array(result);
	}
	else
	{
		printf("[PASS] test_only_separators\n");
		free(result);
	}
}

void	test_no_separator_in_string(void)
{
	char	*str = "HelloWorld";
	char	**result;
	int		passed = 1;
	
	result = ft_split(str, ',');
	
	if (strcmp(result[0], "HelloWorld") != 0)
	{
		printf("[FAIL] test_no_separator_in_string: expected 'HelloWorld', got '%s'\n", result[0]);
		passed = 0;
	}
	if (result[1] != NULL)
	{
		printf("[FAIL] test_no_separator_in_string: expected NULL terminator at index 1\n");
		passed = 0;
	}
	
	if (passed)
		printf("[PASS] test_no_separator_in_string\n");
	
	free_array(result);
}

int	main(void)
{
	test_normal_case();
	test_consecutive_separators();
	test_separators_at_ends();
	test_empty_string();
	test_only_separators();
	test_no_separator_in_string();
	return (0);
}
