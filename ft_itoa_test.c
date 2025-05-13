/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 00:00:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/13 00:00:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void	test_positive_number(void)
{
	int		n = 12345;
	char	*result;
	char	expected[] = "12345";
	
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_positive_number\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_positive_number\n");
	}
	free(result);
}

void	test_negative_number(void)
{
	int		n = -12345;
	char	*result;
	char	expected[] = "-12345";
	
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_negative_number\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_negative_number\n");
	}
	free(result);
}

void	test_zero(void)
{
	int		n = 0;
	char	*result;
	char	expected[] = "0";
	
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_zero\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_zero\n");
	}
	free(result);
}

void	test_int_max(void)
{
	int		n = INT_MAX;
	char	*result;
	char	expected[12];
	
	sprintf(expected, "%d", INT_MAX);
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_int_max\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_int_max\n");
	}
	free(result);
}

void	test_int_min(void)
{
	int		n = INT_MIN;
	char	*result;
	char	expected[12];
	
	sprintf(expected, "%d", INT_MIN);
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_int_min\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_int_min\n");
	}
	free(result);
}

void	test_single_digit(void)
{
	int		n = 7;
	char	*result;
	char	expected[] = "7";
	
	result = ft_itoa(n);
	if (strcmp(result, expected) != 0)
	{
		printf("[FAIL] test_single_digit\n");
		printf("       Got: %s, Expected: %s\n", result, expected);
	}
	else
	{
		printf("[PASS] test_single_digit\n");
	}
	free(result);
}

int	main(void)
{
	test_positive_number();
	test_negative_number();
	test_zero();
	test_int_max();
	test_int_min();
	test_single_digit();
	return (0);
}
