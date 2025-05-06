/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:14:48 by carloga2          #+#    #+#             */
/*   Updated: 2025/04/23 19:42:36 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test_basic_copy(void)
{
	char	dst1[100];
	char	dst2[100];
	const char	src[] = "Hello, world!";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcpy(dst1, src, sizeof(dst1));
	ret2 = strlcpy(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, src) == 0 && ret1 == ret2)
		printf("[PASS] Basic copy test\n");
	else
		printf("[FAIL] Basic copy test\n");
}

void	test_size_limit(void)
{
	char	dst1[6];
	char	dst2[6];
	const char	src[] = "Hello, world!";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcpy(dst1, src, sizeof(dst1));
	ret2 = strlcpy(dst2, src, sizeof(dst2));
	
	if (strcmp(dst1, dst2) == 0 && ret1 == ret2 && strlen(dst1) == 5 && dst1[5] == '\0')
		printf("[PASS] Size limit test\n");
	else
		printf("[FAIL] Size limit test\n");
}

void	test_zero_size(void)
{
	char	dst1[10] = "AAAAAAAAAA";
	char	dst2[10] = "AAAAAAAAAA";
	const char	src[] = "Hello";
	size_t	ret1;
	size_t	ret2;

	ret1 = ft_strlcpy(dst1, src, 0);
	ret2 = strlcpy(dst2, src, 0);

	/* Both should return src length and leave dst unchanged */
	if (ret1 == strlen(src) && ret1 == ret2 && 
		memcmp(dst1, "AAAAAAAAAA", 10) == 0 &&
		memcmp(dst2, "AAAAAAAAAA", 10) == 0)
		printf("[PASS] Zero size test\n");
	else
		printf("[FAIL] Zero size test\n");
}

void	test_empty_src(void)
{
	char	dst[10] = "AAAAAAAAAA";
	const char	src[] = "";
	size_t	ret;

	ret = ft_strlcpy(dst, src, sizeof(dst));

	if (ret == 0 && dst[0] == '\0')
		printf("[PASS] Empty source test\n");
	else
		printf("[FAIL] Empty source test\n");
}

int	main(void)
{
	test_basic_copy();
	test_size_limit();
	test_zero_size();
	test_empty_src();
	return (0);
}