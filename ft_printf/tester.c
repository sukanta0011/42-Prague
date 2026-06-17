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

void	test_c_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing c Bonus ==============//\n");
	printf("\n//============== Flag - ==============//\n");
	printf("------Test1---------\n");
	len = printf("%-10c\n", 'a');
	ft_len = ft_printf("%-10c\n", 'a');
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_s_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing s Bonus ==============//\n");
	printf("\n//============== Flag - ==============//\n");
	printf("------Test: %%-0.5s, Hello World---------\n");
	len = printf("%-0.5s\n", "Hello World");
	ft_len = ft_printf("%-0.5s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%10.5s, Hello World---------\n");
	len = printf("%10.5s\n", "Hello World");
	ft_len = ft_printf("%10.5s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%10s, Hello World---------\n");
	len = printf("%10s\n", "Hello World");
	ft_len = ft_printf("%10s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%20s, Hello World---------\n");
	len = printf("%20s\n", "Hello World");
	ft_len = ft_printf("%20s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-.15s, Hello World---------\n");
	len = printf("%-.15s\n", "Hello World");
	ft_len = ft_printf("%-.15s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-20.15s, Hello World---------\n");
	len = printf("%-20.15s\n", "Hello World");
	ft_len = ft_printf("%-20.15s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-13.15s, Hello World---------\n");
	len = printf("%-13.15s\n", "Hello World");
	ft_len = ft_printf("%-13.15s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% 13.15s, Hello World---------\n");
	len = printf("% 13.15s\n", "Hello World");
	ft_len = ft_printf("% 13.15s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-10.5s, Hello World---------\n");
	len = printf("%-10.5s\n", "Hello World");
	ft_len = ft_printf("%-10.5s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%10.5s, Hello World---------\n");
	len = printf("%10.5s\n", "Hello World");
	ft_len = ft_printf("%10.5s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%- .5s, Hello World---------\n");
	len = printf("%- .5s\n", "Hello World");
	ft_len = ft_printf("%- .5s\n", "Hello World");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% 8s, Hello---------\n");
	len = printf("% 8s\n", "Hello");
	ft_len = ft_printf("% 8s\n", "Hello");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% s, ---------\n");
	len = printf("% s\n", "");
	ft_len = ft_printf("% s\n", "");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%--4.1s, for, ---------\n");
	len = printf("%--4.1s\n", "for");
	ft_len = ft_printf("%--4.1s\n", "for");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% ------------------9.3s, goooood, ---------\n");
	len = printf("%------------------9.3s\n", "goooood");
	ft_len = ft_printf("%------------------9.3s\n", "goooood");
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-5.7s, us, ---------\n");
	len = printf("%-5.7s\n", "us");
	ft_len = ft_printf("%-5.7s\n", "us");
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_x_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing x Bonus ==============//\n");
	printf("\n//============== Flag - ==============//\n");
	printf("------Test: %%042.2x, 42000---------\n");
	len = printf("%042.2x\n", 42000);
	ft_len = ft_printf("%042.2x\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%042x, 42000---------\n");
	len = printf("%042x\n", 42000);
	ft_len = ft_printf("%042x\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%10.5x, 42000---------\n");
	len = printf("%10.5x\n", 42000);
	ft_len = ft_printf("%10.5x\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%5.10x, 42000---------\n");
	len = printf("%5.10x\n", 42000);
	ft_len = ft_printf("%5.10x\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% 5.10x, 42000---------\n");
	len = printf("% 5.10x\n", 42000);
	ft_len = ft_printf("% 5.10x\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% 5.10x, (void *)0---------\n");
	len = printf("% 5.10x\n", (void *)0);
	ft_len = ft_printf("% 5.10x\n", (void *)0);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% x, (void *)0---------\n");
	len = printf("% x\n", (void *)0);
	ft_len = ft_printf("% x\n", (void *)0);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%#x, 42---------\n");
	len = printf("%#x\n", 42);
	ft_len = ft_printf("%#x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%#.10x, 42---------\n");
	len = printf("%#.10x\n", 42);
	ft_len = ft_printf("%#.10x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%#10x, 42---------\n");
	len = printf("%#10x\n", 42);
	ft_len = ft_printf("%#10x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%+10x, 42---------\n");
	len = printf("%+10x\n", 42);
	ft_len = ft_printf("%+10x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%010x, 42---------\n");
	len = printf("%010x\n", 42);
	ft_len = ft_printf("%010x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%#010x, 42---------\n");
	len = printf("%#010x\n", 42);
	ft_len = ft_printf("%#010x\n", 42);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_u_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing u Bonus ==============//\n");
	printf("\n//============== Flag - ==============//\n");
	printf("------Test1---------\n");
	len = printf("%1.0u\n", -10);
	ft_len = ft_printf("%1.0u\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_d_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing d Bonus ==============//\n");
	printf("\n//============== Flag num ==============//\n");
	printf("\n------Test: %% d, 0---------\n");
	len = printf("% d\n", 0);
	ft_len = ft_printf("% d\n", 0);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test: %% d, -1---------\n");
	len = printf("%d\n", -1);
	ft_len = ft_printf("%d\n", -1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %% 03d, -1---------\n");
	len = printf("% 03d\n", -1);
	ft_len = ft_printf("% 03d\n", -1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test: %% 03d, 1---------\n");
	len = printf("% 03d\n", 1);
	ft_len = ft_printf("% 03d\n", 1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test: %% 10.5d, -1---------\n");
	len = printf("% 10.5d\n", -1);
	ft_len = ft_printf("% 10.5d\n", -1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %%10.5d, -1---------\n");
	len = printf("%10.5d\n", -1);
	ft_len = ft_printf("%10.5d\n", -1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %% 10.5d, 1---------\n");
	len = printf("% 10.5d\n", 1);
	ft_len = ft_printf("% 10.5d\n", 1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %%10.5d, 1---------\n");
	len = printf("%10.5d\n", 1);
	ft_len = ft_printf("%10.5d\n", 1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test: %% 5.10d, -1---------\n");
	len = printf("% 5.10d\n", -1);
	ft_len = ft_printf("% 5.10d\n", -1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test: %% 05.10d, 1---------\n");
	len = printf("% 5.10d\n", 1);
	ft_len = ft_printf("% 5.10d\n", 1);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %%020.20i, -42000---------\n");
	len = printf("%020.20i\n", -42000);
	ft_len = ft_printf("%020.20i\n", -42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %%+020.20i, -42000---------\n");
	len = printf("%+020.20i\n", 42000);
	ft_len = ft_printf("%+020.20i\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("\n------Test:  %%020.20i, 42000---------\n");
	len = printf("%020.20i\n", 42000);
	ft_len = ft_printf("%020.20i\n", 42000);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

void	test_p_bonus(void)
{
	int	len;
	int	ft_len;

	printf("\n//============== Testing p Bonus ==============//\n");
	printf("\n//============== Flag num ==============//\n");
	printf("------Test: %%14p, -10---------\n");
	len = printf("%14p\n", -10);
	ft_len = ft_printf("%14p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-14p, -10---------\n");
	len = printf("%-14p\n", -10);
	ft_len = ft_printf("%-14p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% 14p, -10---------\n");
	len = printf("% 14p\n", -10);
	ft_len = ft_printf("% 14p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%014p, -10---------\n");
	len = printf("%014p\n", -10);
	ft_len = ft_printf("%014p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%-14p, -10---------\n");
	len = printf("%-14p\n", -10);
	ft_len = ft_printf("%-14p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%16p, -10---------\n");
	len = printf("%16p\n", -10);
	ft_len = ft_printf("%16p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test3: %%13p is the address, (void *)0x7ffe6b8e60c8---------\n");
	len = printf("%16p is the address\n", (void *)0x7ffe6b8e60c8);
	ft_len = ft_printf("%16p is the address\n", (void *)0x7ffe6b8e60c8);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %% p, NULL---------\n");
	len = printf("% p\n", NULL);
	ft_len = ft_printf("% p\n", NULL);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%.10p, -10---------\n");
	len = printf("%.10p\n", -10);
	ft_len = ft_printf("%.10p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%.4p, -10---------\n");
	len = printf("%.4p\n", -10);
	ft_len = ft_printf("%.4p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%.8p, -10---------\n");
	len = printf("%.8p\n", -10);
	ft_len = ft_printf("%.8p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%12.15p, -10---------\n");
	len = printf("%12.15p\n", -10);
	ft_len = ft_printf("%12.15p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
	printf("------Test: %%15.12p, -10---------\n");
	len = printf("%15.12p\n", -10);
	ft_len = ft_printf("%15.12p\n", -10);
	printf("len = %d, ft_len = %d\n", len, ft_len);
}

int	main(void)
{
	// test_c();
	// test_s();
	// test_p();
	// test_d();
	// test_i();
	// test_u();
	// test_x();
	// test_X();
	// test_per();
	// test_mix();
	// test_s_bonus();
	test_x_bonus();
	// test_d_bonus();
	// test_p_bonus();

	return (0);
}