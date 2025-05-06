/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:10:00 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/05 16:10:00 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void    test_positive_number(void)
{
        char    *str = "12345";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_positive_number\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_positive_number\n");
        }
}

void    test_negative_number(void)
{
        char    *str = "-12345";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_negative_number\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_negative_number\n");
        }
}

void    test_with_whitespace(void)
{
        char    *str = "   \t\n\v\f\r  42";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_with_whitespace\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_with_whitespace\n");
        }
}

void    test_with_plus_sign(void)
{
        char    *str = "+12345";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_with_plus_sign\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_with_plus_sign\n");
        }
}

void    test_with_chars_after_number(void)
{
        char    *str = "12345abc";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_with_chars_after_number\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_with_chars_after_number\n");
        }
}

void    test_with_chars_before_number(void)
{
        char    *str = "abc12345";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_with_chars_before_number\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_with_chars_before_number\n");
        }
}

void    test_empty_string(void)
{
        char    *str = "";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_empty_string\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_empty_string\n");
        }
}

void    test_multiple_signs(void)
{
        char    *str = "+-42";
        int     result;
        int     expected;

        result = ft_atoi(str);
        expected = atoi(str);
        if (result != expected)
        {
                printf("[FAIL] test_multiple_signs\n");
                printf("       Got: %d, Expected: %d\n", result, expected);
        }
        else
        {
                printf("[PASS] test_multiple_signs\n");
        }
}

int     main(void)
{
        test_positive_number();
        test_negative_number();
        test_with_whitespace();
        test_with_plus_sign();
        test_with_chars_after_number();
        test_with_chars_before_number();
        test_empty_string();
        test_multiple_signs();
        return (0);
}