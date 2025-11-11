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
    unsigned int    outputs[3] = {5, 0};

    printf("\n------------ft_strlen--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_strlen(inputs[i]) == outputs[i])
            printf("Input: %s, output: %d. %sOK%s\n", inputs[i], ft_strlen(inputs[i]), GREEN, RESET);
        else
            printf("Input: %s, output: %d. %sKO%s\n", inputs[i], ft_strlen(inputs[i]), RED, RESET);
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
    char    src[10] = "Something";
    char    src1[10] = "Something";
    char    src2[10] = "Something";
    char    dst[11] = "HelloWorld";
    char    *r_dst;
    char    *l_dst;

    r_dst = &src1[2];
    l_dst = src2;

    printf("\n------------ft_memmove--------------\n");
    if (!strncmp(ft_memmove(dst, src, 5), "SometWorld", 10))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
    if (!strncmp(ft_memmove(r_dst, src1, 4), "Someing", 7))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, r_dst, RESET, src1, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, r_dst, RESET, src1, RED, RESET);
	if (!strncmp(ft_memmove(l_dst, &src2[4], 4), "thinthing", 9))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, l_dst, RESET, &src2[4], GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, l_dst, RESET, &src2[4], RED, RESET);
}

void    ft_strlcpy_test(void)
{
    char    src[10] = "Something";
    char    src1[10] = "Something";
    char    src2[10] = "Something";
    char    dst[11] = "HelloWorld";
    char    dst1[10] = "Hello";
    char    dst2[5] = "Hello";

    printf("\n------------ft_strlcpy--------------\n");
	ft_strlcpy(dst, src, 11);
    if (!strncmp(dst, "SometWorld", 10))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
	ft_strlcpy(dst1, src1, 11);
    if (!strncmp(dst1, "Someing", 10))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst1, RESET, src1, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst1, RESET, src1, RED, RESET);
	ft_strlcpy(dst2, src2, 0);
	if (!strncmp(dst2, "thinthing", 0))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst2, RESET, src2, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst2, RESET, src2, RED, RESET);
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
	ft_strlcpy_test();
    return (0);
}