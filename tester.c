/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:09:57 by sudas             #+#    #+#             */
/*   Updated: 2025/11/17 09:09:57 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	test_c(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing c ==============//\n");
	printf("------Test1---------\n");
	len = printf("%c\n", 0);
	ft_len = ft_printf("%c\n", 0);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %c\n", 'a');
	ft_len = ft_printf("Test with string: %c\n", 'a');
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple c: %c, %c, %c\n", 'a', 'b', 0);
	ft_len = ft_printf("Test with string and multiple c: %c, %c, %c\n", 'a', 'b', 0);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_s(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing s ==============//\n");
	printf("------Test1---------\n");
	len = printf("%s\n", NULL);
	ft_len = ft_printf("%s\n", NULL);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %s\n", "Hello");
	ft_len = ft_printf("Test with string: %s\n", "Hello");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple s: %s, %s\n", "Hello", "World");
	ft_len = ft_printf("Test with string and multiple s: %s, %s\n", "Hello", "World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_p(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing p ==============//\n");
	printf("------Test1---------\n");
	len = printf("%p\n", "Hello");
	ft_len = ft_printf("%p\n", "Hello");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %p\n", "Hello");
	ft_len = ft_printf("Test with string: %p\n", "Hello");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple p: %p, %p\n", "Hello", 123);
	ft_len = ft_printf("Test with string and multiple p: %p, %p\n", "Hello", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Null pointer: %p\n", 0);
	ft_len = ft_printf("Null pointer: %p\n", NULL);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_d(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing d ==============//\n");
	printf("------Test1---------\n");
	len = printf("%d\n", 123);
	ft_len = ft_printf("%d\n", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %d\n", -123);
	ft_len = ft_printf("Test with string: %d\n", -123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple d: %d, %d\n", 123, -456);
	ft_len = ft_printf("Test with string and multiple d: %d, %d\n", 123, -456);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Test with min max: %d, %d\n", INT_MIN, INT_MAX);
	ft_len = ft_printf("Test with min max: %d, %d\n", INT_MIN, INT_MAX);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_i(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing i ==============//\n");
	printf("------Test1---------\n");
	len = printf("%i\n", 123);
	ft_len = ft_printf("%i\n", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %i\n", -123);
	ft_len = ft_printf("Test with string: %i\n", -123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple d: %i, %i\n", 123, -456);
	ft_len = ft_printf("Test with string and multiple d: %i, %i\n", 123, -456);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Test with min max: %i, %i\n", INT_MIN, INT_MAX);
	ft_len = ft_printf("Test with min max: %i, %i\n", INT_MIN, INT_MAX);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_u(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing u ==============//\n");
	printf("------Test1---------\n");
	len = printf("%u\n", 123);
	ft_len = ft_printf("%u\n", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %u\n", -123);
	ft_len = ft_printf("Test with string: %u\n", -123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple d and overflow: %u, %u\n", 123, -456);
	ft_len = ft_printf("Test with string and multiple d and overflow: %u, %u\n", 123, -456);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Test with min max: %u, %u\n", 0, UINT_MAX);
	ft_len = ft_printf("Test with min max: %u, %u\n", 0, UINT_MAX);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_x(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing x ==============//\n");
	printf("------Test1---------\n");
	len = printf("%x\n", 123);
	ft_len = ft_printf("%x\n", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %x\n", -123);
	ft_len = ft_printf("Test with string: %x\n", -123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple d and overflow: %x, %x\n", 123, -456);
	ft_len = ft_printf("Test with string and multiple d and overflow: %x, %x\n", 123, -456);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Test with min max: %x, %x\n", 0, UINT_MAX);
	ft_len = ft_printf("Test with min max: %x, %x\n", 0, UINT_MAX);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_X(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing X ==============//\n");
	printf("------Test1---------\n");
	len = printf("%X\n", 123);
	ft_len = ft_printf("%X\n", 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %X\n", -123);
	ft_len = ft_printf("Test with string: %X\n", -123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3---------\n");
	len = printf("Test with string and multiple d and overflow: %X, %X\n", 123, -456);
	ft_len = ft_printf("Test with string and multiple d and overflow: %X, %X\n", 123, -456);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test4---------\n");
	len = printf("Test with min max: %X, %X\n", 0, UINT_MAX);
	ft_len = ft_printf("Test with min max: %X, %X\n", 0, UINT_MAX);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_per(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing per ==============//\n");
	printf("------Test1---------\n");
	len = printf("%%\n");
	ft_len = ft_printf("%%\n");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test2---------\n");
	len = printf("Test with string: %%\n");
	ft_len = ft_printf("Test with string: %%\n");
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_mix(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing per ==============//\n");
	printf("------Test1---------\n");
	len = printf("%%, %c, %s, %d, %p, %x, %i\n", 'a', "Hello", 123, "Hi", 123, 123);
	ft_len = ft_printf("%%, %c, %s, %d, %p, %x, %i\n", 'a', "Hello", 123, "Hi", 123, 123);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

int	main(void)
{
	// test_c();
	// test_s();
	test_p();
	// test_d();
	// test_i();
	// test_u();
	// test_x();
	// test_X();
	// test_per();
	// test_mix();

	return (0);
}