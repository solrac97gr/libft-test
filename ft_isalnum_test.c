/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:57:09 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 20:28:33 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	if_isalnum_get_digit_return_nonzero(void)
{
	int	res_is_nonzero;
	int	expected_is_nonzero;

	res_is_nonzero = ft_isalnum(5) != 0;
	expected_is_nonzero = isalnum(5) != 0;
	if (res_is_nonzero != expected_is_nonzero)
	{
		printf("[FAIL] if_isalnum_get_digit_return_nonzero\n");
	}
	else
	{
		printf("[PASS] if_isalnum_get_digit_return_nonzero\n");
	}
}

void	if_isalnum_get_letter_return_nonzero(void)
{
	int	res_is_nonzero;
	int	expected_is_nonzero;

	res_is_nonzero = ft_isalnum('A') != 0;
	expected_is_nonzero = isalnum('A') != 0;
	if (res_is_nonzero != expected_is_nonzero)
	{
		printf("[FAIL] if_isalnum_get_letter_return_nonzero\n");
	}
	else
	{
		printf("[PASS] if_isalnum_get_letter_return_nonzero\n");
	}
}

void	if_isalnum_get_symbol_return_0(void)
{
	int	res;
	int	expected;

	res = ft_isalnum('+');
	expected = isalnum('+');
	if (res != expected)
	{
		printf("[FAIL] if_isalnum_get_symbol_return_0\n");
	}
	else
	{
		printf("[PASS] if_isalnum_get_symbol_return_0\n");
	}
}

int	main(void)
{
	if_isalnum_get_digit_return_nonzero();
	if_isalnum_get_letter_return_nonzero();
	if_isalnum_get_symbol_return_0();
}