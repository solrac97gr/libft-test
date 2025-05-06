/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:20:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/06 21:20:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	test_normal_string(void)
{
	const char	*original = "Hello, world!";
	char		*dup1;
	char		*dup2;
	int			result;

	dup1 = ft_strdup(original);
	dup2 = strdup(original);
	if (!dup1 || !dup2)
	{
		printf("[FAIL] test_normal_string: allocation failed\n");
		if (dup1)
			free(dup1);
		if (dup2)
			free(dup2);
		return ;
	}
	result = strcmp(dup1, dup2);
	if (result != 0)
	{
		printf("[FAIL] test_normal_string: strings don't match\n");
		printf("       Expected: \"%s\", Got: \"%s\"\n", dup2, dup1);
	}
	else if (dup1 == original || dup2 == original)
	{
		printf("[FAIL] test_normal_string: returned original string pointer\n");
	}
	else
	{
		printf("[PASS] test_normal_string\n");
	}
	free(dup1);
	free(dup2);
}

void	test_empty_string(void)
{
	const char	*original = "";
	char		*dup1;
	char		*dup2;
	int			result;

	dup1 = ft_strdup(original);
	dup2 = strdup(original);
	if (!dup1 || !dup2)
	{
		printf("[FAIL] test_empty_string: allocation failed\n");
		if (dup1)
			free(dup1);
		if (dup2)
			free(dup2);
		return ;
	}
	result = strcmp(dup1, dup2);
	if (result != 0)
	{
		printf("[FAIL] test_empty_string: strings don't match\n");
		printf("       Expected: \"%s\", Got: \"%s\"\n", dup2, dup1);
	}
	else
	{
		printf("[PASS] test_empty_string\n");
	}
	free(dup1);
	free(dup2);
}

void	test_long_string(void)
{
	char	original[1000];
	char	*dup1;
	char	*dup2;
	int		i;
	int		result;

	// Create a long string
	for (i = 0; i < 998; i++)
		original[i] = 'a' + (i % 26);
	original[998] = '\0';
	dup1 = ft_strdup(original);
	dup2 = strdup(original);
	if (!dup1 || !dup2)
	{
		printf("[FAIL] test_long_string: allocation failed\n");
		if (dup1)
			free(dup1);
		if (dup2)
			free(dup2);
		return ;
	}
	result = strcmp(dup1, dup2);
	if (result != 0)
	{
		printf("[FAIL] test_long_string: strings don't match\n");
	}
	else if (dup1 == original || dup2 == original)
	{
		printf("[FAIL] test_long_string: returned original string pointer\n");
	}
	else
	{
		printf("[PASS] test_long_string\n");
	}
	free(dup1);
	free(dup2);
}

void	test_special_characters(void)
{
	const char	*original = "Special\tcharacters\nincluding\rsome\0hidden\0ones";
	char		*dup1;
	char		*dup2;
	int			result;

	dup1 = ft_strdup(original);
	dup2 = strdup(original);
	if (!dup1 || !dup2)
	{
		printf("[FAIL] test_special_characters: allocation failed\n");
		if (dup1)
			free(dup1);
		if (dup2)
			free(dup2);
		return ;
	}
	// Since strcmp stops at null bytes, we need to compare the first part only
	// or use memcmp with a specific length
	result = strcmp(dup1, dup2);
	if (result != 0)
	{
		printf("[FAIL] test_special_characters: strings don't match\n");
		printf("       Expected: \"%s\", Got: \"%s\"\n", dup2, dup1);
	}
	else
	{
		printf("[PASS] test_special_characters\n");
	}
	free(dup1);
	free(dup2);
}

void	test_null_termination(void)
{
	const char	*original = "Test null termination";
	char		*dup;
	size_t		len;

	dup = ft_strdup(original);
	if (!dup)
	{
		printf("[FAIL] test_null_termination: allocation failed\n");
		return ;
	}
	len = ft_strlen(original);
	if (dup[len] != '\0')
	{
		printf("[FAIL] test_null_termination: string not properly null-terminated\n");
	}
	else
	{
		printf("[PASS] test_null_termination\n");
	}
	free(dup);
}

int	main(void)
{
	test_normal_string();
	test_empty_string();
	test_long_string();
	test_special_characters();
	test_null_termination();
	return (0);
}