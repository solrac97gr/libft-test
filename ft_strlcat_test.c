/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:15:34 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/23 20:15:34 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test_basic_concatenation(void)
{
	char	dst1[100] = "Hello, ";
	char	dst2[100] = "Hello, ";
	const char	src[] = "world!";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcat(dst1, src, sizeof(dst1));
	ret2 = strlcat(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2)
		printf("[PASS] Basic concatenation test\n");
	else
		printf("[FAIL] Basic concatenation test\n");
}

void	test_size_limit(void)
{
	char	dst1[15] = "Hello, ";
	char	dst2[15] = "Hello, ";
	const char	src[] = "world with a very long name!";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcat(dst1, src, sizeof(dst1));
	ret2 = strlcat(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2 && strlen(dst1) == 14 && dst1[14] == '\0')
		printf("[PASS] Size limit test\n");
	else
		printf("[FAIL] Size limit test\n");
}

void	test_size_too_small(void)
{
	char	dst1[10] = "Hello, ";
	char	dst2[10] = "Hello, ";
	const char	src[] = "world!";
	size_t	ret1;
	size_t	ret2;

	/* Test with size less than dst length */
	ret1 = ft_strlcat(dst1, src, 5);
	ret2 = strlcat(dst2, src, 5);
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2)
		printf("[PASS] Size too small test\n");
	else
		printf("[FAIL] Size too small test\n");
}

void	test_empty_dst(void)
{
	char	dst1[10] = "";
	char	dst2[10] = "";
	const char	src[] = "Hello!";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcat(dst1, src, sizeof(dst1));
	ret2 = strlcat(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2)
		printf("[PASS] Empty destination test\n");
	else
		printf("[FAIL] Empty destination test\n");
}

void	test_empty_src(void)
{
	char	dst1[10] = "Hello!";
	char	dst2[10] = "Hello!";
	const char	src[] = "";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcat(dst1, src, sizeof(dst1));
	ret2 = strlcat(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2)
		printf("[PASS] Empty source test\n");
	else
		printf("[FAIL] Empty source test\n");
}

int	main(void)
{
	test_basic_concatenation();
	test_size_limit();
	test_size_too_small();
	test_empty_dst();
	test_empty_src();
	return (0);
}