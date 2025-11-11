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

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

void    ft_isalpha_test(void)
{
    char    inputs[] = {'a', 'z', '~', '1', 'Z'};
    int    outputs[] = {1, 1, 0, 0, 1};

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
    char    inputs[] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[] = {0, 0, 0, 1, 0, 0};

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
    char    inputs[] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[] = {1, 1, 0, 1, 1, 0};

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
    char    inputs[] = {'a', 'z', '~', '1', 'Z', ' '};
    int    outputs[] = {1, 1, 1, 1, 1, 1};

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
    char    inputs[] = {'a', '\t', '~', '1', 'Z', '\1'};
    int    outputs[] = {1, 0, 1, 1, 1, 0};

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
    char    *inputs[] = {"Hello", "", '\0'};
    int    outputs[] = {5, 0, '\0'};

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
    char    *mem;

    mem = malloc(10);
    printf("\n------------ft_memset--------------\n");
    ft_memset(mem, 'a', 5);
    printf("5 memory block set with char 'c': %s \n", mem);
    ft_memset(mem, 'b', 1);
    printf("1 memory block set with char 'b': %s\n", mem);
    ft_memset(mem, 'c', 8);
    printf("8 memory block set with char 'c': %s\n", mem);
}

void    ft_bzero_test(void)
{
    char    *mem;

    mem = malloc(10);
    printf("\n------------ft_bzero--------------\n");
    ft_bzero(mem, 5);
    printf("5 memory block is set: %s \n", mem);
    ft_bzero(mem, 1);
    printf("1 memory block is set: %s\n", mem);
}

void    ft_memcpy_test(void)
{
    char    src[10] = "Hello";
    char    dst[10] = "";

    printf("\n------------ft_memcpy--------------\n");
    ft_memcpy(dst, src, 2);
    printf("Destination: %s, Source: %s. Memory block copied: 2\n", dst, src);
    ft_memcpy(dst, src, 4);
    printf("Destination: %s, Source: %s. Memory block copied: 4\n", dst, src);
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