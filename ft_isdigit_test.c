/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:42:59 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/21 19:52:01 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	if_is_digit_return_1(void)
{
	int	res;
	int	expected;

	res = ft_isdigit(5);
	expected = isdigit(5);
	if (res != expected)
	{
		printf("[FAIL] if_is_digit_return_1\n");
	}
	else
	{
		printf("[PASS] if_is_digit_return_1\n");
	}
}

void	if_is_not_digit_return_0(void)
{
	int	res;
	int	expected;

	res = ft_isdigit('a');
	expected = isdigit('a');
	if (res != expected)
	{
		printf("[FAIL] if_is_not_digit_return_0\n");
	}
	else
	{
		printf("[PASS] if_is_not_digit_return_0\n");
	}
}

int	main(void)
{
	if_is_digit_return_1();
	if_is_not_digit_return_0();
}