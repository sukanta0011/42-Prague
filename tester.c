/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:38:11 by sudas             #+#    #+#             */
/*   Updated: 2025/11/11 13:38:11 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BLUE	"\x1b[34m"


void    ft_isalpha_test(void)
{
    char    inputs[6] = {'a', 'z', '~', '1', 'Z'};
    int    outputs[6] = {1, 1, 0, 0, 1};

    printf("\n------------ft_isalpha--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_isalpha(inputs[i]) == outputs[i])
            printf("Input: %c, output: %d. %s OK %s\n", inputs[i], ft_isprint(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %d. %s KO %s\n", inputs[i], ft_isprint(inputs[i]), RED, RESET);
    }
}

void    ft_isdigit_test(void)
{
    char    inputs[7] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[7] = {0, 0, 0, 1, 0, 0};

    printf("\n------------ft_isalpha--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_isdigit(inputs[i]) == outputs[i])
            printf("Input: %c, output: %d. %s OK %s\n", inputs[i], ft_isdigit(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %d. %s KO %s\n", inputs[i], ft_isdigit(inputs[i]), RED, RESET);
    }
}

void    ft_isalnum_test(void)
{
    char    inputs[7] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[7] = {1, 1, 0, 1, 1, 0};

    printf("\n------------ft_isalnum--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_isalnum(inputs[i]) == outputs[i])
            printf("Input: %c, output: %d. %s OK %s\n", inputs[i], ft_isalnum(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %d. %s KO %s\n", inputs[i], ft_isalnum(inputs[i]), RED, RESET);
    }
}

void    ft_isascii_test(void)
{
    char    inputs[7] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[7] = {1, 1, 1, 1, 1, 1};

    printf("\n------------ft_isascii--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_isascii(inputs[i]) == outputs[i])
            printf("Input: %c, output: %d. %s OK %s\n", inputs[i], ft_isascii(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %d. %s KO %s\n", inputs[i], ft_isascii(inputs[i]), RED, RESET);
    }
}

void    ft_isprint_test(void)
{
    char    inputs[7] = {'a', '\t', '~', '1', 'Z', '\1'};
    int    outputs[7] = {1, 0, 1, 1, 1, 0};

    printf("\n------------ft_isprint--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_isprint(inputs[i]) == outputs[i])
            printf("Input: %c, output: %d. %s OK %s\n", inputs[i], ft_isprint(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %d. %s KO %s\n", inputs[i], ft_isprint(inputs[i]), RED, RESET);
    }
}

void    ft_strlen_test(void)
{
    char    *inputs[3] = {"Hello", ""};
    int    outputs[3] = {5, 0};

    printf("\n------------ft_strlen--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_strlen(inputs[i]) == outputs[i])
            printf("Input: %s, output: %d. %s OK %s\n", inputs[i], ft_strlen(inputs[i]), GREEN, RESET);
        else
            printf("Input: %s, output: %d. %s KO %s\n", inputs[i], ft_strlen(inputs[i]), RED, RESET);
    }
}

void    ft_memset_test(void)
{
    char    mem[10];

    printf("\n------------ft_memset--------------\n");
    if (!strncmp(ft_memset(mem, 'a', 5), "aaaaa", 5))
    	printf("5 memory block set with char 'a':%s %s%s. %sOK%s \n", BLUE, mem, RESET, GREEN, RESET);
	else
    	printf("5 memory block set with char 'a':%s %s%s. %sKO%s \n", BLUE, mem, RESET, RED, RESET);
	if (!strncmp(ft_memset(mem, 'b', 1), "baaaa", 5))
    	printf("1 memory block set with char 'b':%s %s%s. %sOK%s \n", BLUE, mem, RESET, GREEN, RESET);
	else
		printf("1 memory block set with char 'b':%s %s%s. %sKO%s \n", BLUE, mem, RESET, RED, RESET);
	if (!strncmp(ft_memset(mem, 'c', 8), "cccccccc", 8))
    	printf("8 memory block set with char 'c':%s %s%s. %sOK%s \n", BLUE, mem, RESET, GREEN, RESET);
	else
    	printf("8 memory block set with char 'c':%s %s%s. %sKO%s \n", BLUE, mem, RESET, RED, RESET);
}

void    ft_bzero_test(void)
{
    char    mem[10];

    printf("\n------------ft_bzero--------------\n");
    ft_bzero(mem, 5);
    printf("5 memory block is set: %s \n", mem);
    ft_bzero(mem, 1);
    printf("1 memory block is set: %s\n", mem);
}

void    ft_memcpy_test(void)
{
    char    src[6] = "Hello";
    char    dst[10] = "Something";

    printf("\n------------ft_memcpy--------------\n");
    if (!strcmp(ft_memcpy(dst, src, 2), "Hemething"))
    	printf("Des: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
		printf("Des: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
    if (!strcmp(ft_memcpy(dst, src, 4), "Hellthing"))
    	printf("Des: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
		printf("Des: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
	if (!strcmp(ft_memcpy(dst, src, 0), "Hellthing"))
    	printf("Des: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
		printf("Des: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
}

void    ft_memmove_test(void)
{
    char    src[20] = "Hello, simple mover";
    char    src1[20] = "Hello";
    char    src2[20] = "It's memmover";
    char    dst[20];
    char    *r_dst;
    char    *l_dst;

    r_dst = &src1[2];
    l_dst = src2;

    printf("\n------------ft_memmove--------------\n");
    ft_memmove(dst, src1, 5);
    printf("Destination: %s, Source: %s. Memory block moved: 5\n", dst, src);
    printf("Memory Left Overlaps\n");
    ft_memmove(r_dst, src1, 4);
    printf("Destination: %s, Source: %s. Memory block moved: 4\n", r_dst, src1);
    printf("Memory Right Overlaps\n");
    ft_memmove(l_dst, &src2[5], 4);
    printf("Destination: %s, Source: %s. Memory block copied: 4\n", l_dst, &src2[5]);
}

int main(void)
{
    ft_isalpha_test();
    ft_isdigit_test();
    ft_isalnum_test();
    ft_isascii_test();
    ft_isprint_test();
    ft_strlen_test();
    ft_memset_test();
    ft_bzero_test();
    ft_memcpy_test();
    ft_memmove_test();
    return (0);
}