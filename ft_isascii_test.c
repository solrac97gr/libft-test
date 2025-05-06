/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 20:45:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	if_isascii_get_ascii_return_1(void)
{
	int	res;
	int	expected;

	res = ft_isascii('A');
	expected = isascii('A');
	if (res != expected)
	{
		printf("[FAIL] if_isascii_get_ascii_return_1\n");
	}
	else
	{
		printf("[PASS] if_isascii_get_ascii_return_1\n");
	}
}

void	if_isascii_get_control_char_return_1(void)
{
	int	res;
	int	expected;

	res = ft_isascii('\n');
	expected = isascii('\n');
	if (res != expected)
	{
		printf("[FAIL] if_isascii_get_control_char_return_1\n");
	}
	else
	{
		printf("[PASS] if_isascii_get_control_char_return_1\n");
	}
}

void	if_isascii_get_extended_char_return_0(void)
{
	int	res;
	int	expected;
	
	// 128 is the first non-ASCII character
	res = ft_isascii(128);
	expected = isascii(128);
	if (res != expected)
	{
		printf("[FAIL] if_isascii_get_extended_char_return_0\n");
	}
	else
	{
		printf("[PASS] if_isascii_get_extended_char_return_0\n");
	}
}

int	main(void)
{
	if_isascii_get_ascii_return_1();
	if_isascii_get_control_char_return_1();
	if_isascii_get_extended_char_return_0();
}