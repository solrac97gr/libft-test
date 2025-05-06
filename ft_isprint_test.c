/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:05:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 21:05:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	if_isprint_get_printable_return_nonzero(void)
{
	int	res_is_nonzero;
	int	expected_is_nonzero;

	res_is_nonzero = ft_isprint('A') != 0;
	expected_is_nonzero = isprint('A') != 0;
	if (res_is_nonzero != expected_is_nonzero)
	{
		printf("[FAIL] if_isprint_get_printable_return_nonzero\n");
	}
	else
	{
		printf("[PASS] if_isprint_get_printable_return_nonzero\n");
	}
}

void	if_isprint_get_space_return_nonzero(void)
{
	int	res_is_nonzero;
	int	expected_is_nonzero;

	res_is_nonzero = ft_isprint(' ') != 0;
	expected_is_nonzero = isprint(' ') != 0;
	if (res_is_nonzero != expected_is_nonzero)
	{
		printf("[FAIL] if_isprint_get_space_return_nonzero\n");
	}
	else
	{
		printf("[PASS] if_isprint_get_space_return_nonzero\n");
	}
}

void	if_isprint_get_control_char_return_0(void)
{
	int	res;
	int	expected;
	
	// '\n' is a control character (ASCII 10), not printable
	res = ft_isprint('\n');
	expected = isprint('\n');
	if (res != expected)
	{
		printf("[FAIL] if_isprint_get_control_char_return_0\n");
	}
	else
	{
		printf("[PASS] if_isprint_get_control_char_return_0\n");
	}
}

void	if_isprint_get_extended_char_return_0(void)
{
	int	res;
	int	expected;
	
	// 127 is DEL character, not printable
	res = ft_isprint(127);
	expected = isprint(127);
	if (res != expected)
	{
		printf("[FAIL] if_isprint_get_extended_char_return_0\n");
	}
	else
	{
		printf("[PASS] if_isprint_get_extended_char_return_0\n");
	}
}

int	main(void)
{
	if_isprint_get_printable_return_nonzero();
	if_isprint_get_space_return_nonzero();
	if_isprint_get_control_char_return_0();
	if_isprint_get_extended_char_return_0();
}