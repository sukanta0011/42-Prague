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
# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <stddef.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BLUE	"\x1b[34m"

//----------------------CUSTOM FUNCTIONS---------------------------//
void    test_ok(const char *test_type, const char *result)
{
    printf("%s: %s%s %sOK%s\n",test_type, BLUE, result, GREEN, RESET);
}
void    test_ko(const char *test_type, const char *result)
{
    printf("%s: %s%s %sKO%s\n",test_type, BLUE, result, RED, RESET);
}

int mem_alloc_check(char *mem, const int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (mem[i] != '\0')
        {
            free(mem);
            return (i);
        }
        i++;
    }
    free(mem);
    return (i);
}

int arr_of_strcmp(char **arr1, char **arr2)
{
    for (int i = 0; arr1[i]; i++)
    {
        // printf("%s\n", arr2[i]);
        if (strcmp(arr1[i], arr2[i]))
            return (0);
    }
    return (1);
}

char    str_toupper(unsigned int idx, char c)
{
    (void)idx;
    if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void    str_tolower(unsigned int idx, char* c)
{
    (void)idx;
    if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

void	my_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
	(*lst) = NULL;
}

t_list	*my_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

//----------------------TESTERS---------------------------//
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
    char    *mem;

    printf("\n------------ft_memset--------------\n");
    mem = malloc(10);
    ft_bzero(mem, 10);
    if (strncmp(ft_memset(mem, 'a', 5), "aaaaa", 5) == 0)
        test_ok("Test1", mem);
	else
    	test_ko("Test1", mem);
	if (strncmp(ft_memset(mem, 'b', 1), "baaaa", 5) == 0)
    	test_ok("Test2", mem);
	else
		test_ko("Test2", mem);
	if (strncmp(ft_memset(mem, 'c', 8), "cccccccc", 8) == 0)
    	test_ok("Test3", mem);
	else
    	test_ko("Test3", mem);
    free(mem);
}

void    ft_bzero_test(void)
{
    char    *mem;

    mem = malloc(10);
    printf("\n------------ft_bzero--------------\n");
    ft_bzero(mem, 5);
    if (mem_alloc_check(mem, 5) == 5)
        test_ok("memblock set", "5");
    else
        test_ok("memblock set", "5");
}

void    ft_memcpy_test(void)
{
    char    src[6] = "Hello";
    char    dst[10] = "Something";

    printf("\n------------ft_memcpy--------------\n");
    if (strcmp(ft_memcpy(dst, src, 2), "Hemething") == 0)
		test_ok("Test1", "Hemething");
	else
		test_ko("Test1", "Hemething");
    if (strcmp(ft_memcpy(dst, src, 4), "Hellthing") == 0)
    	test_ok("Test1", "Hellthing");
	else
		test_ko("Test1", "Hellthing");
	if (strcmp(ft_memcpy(dst, src, 0), "Hellthing") == 0)
    	test_ok("Test1", "Hellthing");
	else
		test_ko("Test1", "Hellthing");
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
    if (strncmp(ft_memmove(dst, src, 5), "SometWorld", 10) == 0)
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
    if (strncmp(ft_memmove(r_dst, src1, 4), "Someing", 7) == 0)
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, r_dst, RESET, src1, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, r_dst, RESET, src1, RED, RESET);
	if (strncmp(ft_memmove(l_dst, &src2[4], 4), "thinthing", 9) == 0)
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, l_dst, RESET, &src2[4], GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, l_dst, RESET, &src2[4], RED, RESET);
}

void    ft_strlcpy_test(void)
{
    char    src[10] = "Something";
    char    src1[10] = "Something";
    char    src2[10] = "Something";
    char    src3[1] = "";
    char    dst[11] = "HelloWorld";
    char    dst1[10] = "Hello";
    char    dst2[6] = "Hello";
    char    dst3[10] = "Hello";

    printf("\n------------ft_strlcpy--------------\n");
    if (ft_strlcpy(dst, src, 4) == 9 && !strncmp(dst, "Som", 10))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst, RESET, src, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst, RESET, src, RED, RESET);
    if (ft_strlcpy(dst1, src1, 11) == 9 && !strncmp(dst1, "Something", 10))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst1, RESET, src1, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst1, RESET, src1, RED, RESET);
	if (ft_strlcpy(dst2, src2, 0) == 9 && !strncmp(dst2, "Hello", 0))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst2, RESET, src2, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst2, RESET, src2, RED, RESET);
    if (ft_strlcpy(dst3, src3, 5) == 0 && !strncmp(dst2, "", 0))
    	printf("Dest: %s%s%s, Src: %s. %sOK%s\n", BLUE, dst3, RESET, src3, GREEN, RESET);
	else
    	printf("Dest: %s%s%s, Src: %s. %sKO%s\n", BLUE, dst3, RESET, src3, RED, RESET);
}

void    ft_strlcat_test(void)
{
    char    src[10] = "Something";
    char    src1[10] = "Something";
    char    src2[10] = "Something";
    char    dst[20] = "HelloWorld";
    char    dst1[20] = "Hello";
    char    dst2[20] = "Hello";

    printf("\n------------ft_strlcat--------------\n");
    if (ft_strlcat(dst, src, 20) == 19 && !strncmp(dst, "HelloWorldSomething", 19))
        test_ok("Full cat", dst);
	else
    	test_ko("Full cat", dst);
    if (ft_strlcat(dst1, src1, 10) == 14 && !strncmp(dst1, "HelloSome", 9))
    	test_ok("Partial cat", dst1);
	else
    	test_ko("Partial cat", dst);
	if (ft_strlcat(dst2, src2, 0) == 9 && !strncmp(dst2, "Hello", 5))
    	test_ok("No cat", dst2);
	else
    	test_ko("No cat", dst2);
}

void    ft_toupper_test(void)
{
    char    inputs[6] = {'a', 'z', 'B', '1', '~'};
    char    outputs[6] = {'A', 'Z', 'B', '1', '~'};

    printf("\n------------ft_toupper--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_toupper(inputs[i]) == outputs[i])
            printf("Input: %c, output: %c. %s OK %s\n", inputs[i], ft_toupper(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %c. %s KO %s\n", inputs[i], ft_toupper(inputs[i]), RED, RESET);
    }
}

void    ft_tolower_test(void)
{
    char    inputs[6] = {'a', 'z', 'B', '1', '~'};
    char    outputs[6] = {'a', 'z', 'b', '1', '~'};

    printf("\n------------ft_tolower--------------\n");
    for (int i = 0; inputs[i]; i++)
    {
        if (ft_tolower(inputs[i]) == outputs[i])
            printf("Input: %c, output: %c. %s OK %s\n", inputs[i], ft_tolower(inputs[i]), GREEN, RESET);
        else
            printf("Input: %c, output: %c. %s KO %s\n", inputs[i], ft_tolower(inputs[i]), RED, RESET);
    }
}

void    ft_strchr_test(void)
{
    char    src[13] = "Hello World\200b";

    printf("\n------------ft_strchr--------------\n");
    if (!strcmp(ft_strchr(src, 'o'), "o World\200b"))
        test_ok("Multi occurrence check", ft_strchr(src, 'o'));
	else
    	test_ko("Multi occurrence check", ft_strchr(src, 'o'));
    if (ft_strchr(src, 'a') == NULL)
    	test_ok("Zero occurrence check", "No char found");
	else
    	test_ko("Zero occurrence check", "No char found");
	if (!strcmp(ft_strchr(src, '\0'), ""))
    	test_ok("Null occurrence check", ft_strchr(src, '\0'));
	else
    	test_ko("Null occurrence check", ft_strchr(src, '\0'));
    if (ft_strchr("", 'o') == NULL)
    	test_ok("Empty source check", "No char found");
	else
    	test_ko("Empty source check", "No char found");
}

void    ft_strrchr_test(void)
{
    char    src[13] = "Hello World\200b";

    printf("\n------------ft_strrchr--------------\n");
    if (!strcmp(ft_strrchr(src, 'o'), "orld\200b"))
        test_ok("Multi occurrence check", ft_strrchr(src, 'o'));
	else
    	test_ko("Multi occurrence check", ft_strrchr(src, 'o'));
    if (ft_strrchr(src, 'a') == NULL)
    	test_ok("Zero occurrence check", "No char found");
	else
    	test_ko("Zero occurrence check", "No char found");
	if (!strcmp(ft_strrchr(src, '\0'), ""))
    	test_ok("Null occurrence check", ft_strrchr(src, '\0'));
	else
    	test_ko("Null occurrence check", ft_strrchr(src, '\0'));
    if (ft_strrchr("", 'o') == NULL)
    	test_ok("Empty source check", "No char found");
	else
    	test_ko("Empty source check", "No char found");
}

void    ft_strncmp_test(void)
{
    char    src[13] = "Hello World\200b";

    printf("\n------------ft_strncmp--------------\n");
    if (!ft_strncmp(src, "He", 2))
    	test_ok("Partial compare", "0");
	else
    	test_ko("Partial compare", "0");
    if (!ft_strncmp(src, "Hello World\200b", 13))
    	test_ok("Full compare", "0");
	else
    	test_ko("Full compare", "0");
    if (ft_strncmp(src, "HellO world", 13) == 32)
    	test_ok("Wrong compare", "diff");
	else
    	test_ko("Wrong compare", "diff");
    if (!ft_strncmp(src, "He", 0))
    	test_ok("n=0 compare", "0");
	else
    	test_ko("n=0 compare", "0");
    if (ft_strncmp("", "He", 2) == -'H')
    	test_ok("s1='' compare", "diff");
	else
    	test_ko("s1='' compare", "diff");
}

void    ft_memchr_test(void)
{
    char    src[13] = "Hello World\200b";

    printf("\n------------ft_memchr--------------\n");
    if (!strcmp(ft_memchr(src, 'o', 13), "o World\200b"))
        test_ok("Multi occurrence check", ft_memchr(src, 'o', 13));
	else
    	test_ko("Multi occurrence check", ft_memchr(src, 'o', 13));
    if (ft_memchr(src, 'a', 13) == NULL)
    	test_ok("Zero occurrence check", "No char found");
	else
    	test_ko("Zero occurrence check", "No char found");
	if (ft_memchr(src, '\0', 13) == NULL)
    	test_ok("Null occurrence check", "");
	else
    	test_ko("Null occurrence check", "");
    if (ft_memchr("", 'o', 13) == NULL)
    	test_ok("Empty source check", "No char found");
	else
    	test_ko("Empty source check", "No char found");
}

void    ft_memcmp_test(void)
{
    char    src[13] = "Hello World\200b";

    printf("\n------------ft_memcmp--------------\n");
    if (!ft_memcmp(src, "He", 2))
    	test_ok("Partial compare", "0");
	else
    	test_ko("Partial compare", "0");
    if (!ft_memcmp(src, "Hello World\200b", 13))
    	test_ok("Full compare", "0");
	else
    	test_ko("Full compare", "0");
    if (ft_memcmp(src, "HellO world", 13) == 32)
    	test_ok("Wrong compare", "diff");
	else
    	test_ko("Wrong compare", "diff");
    if (!ft_memcmp(src, "He", 0))
    	test_ok("n=0 compare", "0");
	else
    	test_ko("n=0 compare", "0");
    if (ft_memcmp("test\200a", "test\0", 6) == 128)
    	test_ok("Wrong compare 2", "diff");
	else
    	test_ko("Wrong compare 2", "diff");
}

void    ft_strnstr_test(void)
{
    printf("\n------------ft_strnstr--------------\n");
    if (!strcmp(ft_strnstr("Hello World", "Wor", 11), "World"))
    	test_ok("Full compare", ft_strnstr("Hello World", "Wor", 11));
	else
    	test_ko("Full compare", ft_strnstr("Hello World", "Wor", 11));
    if (ft_strnstr("Hello World", "Wor", 4) == NULL)
    	test_ok("Wrong compare 1", "null");
	else
    	test_ko("Wrong compare 1", "null");
    if (!strcmp(ft_strnstr("Hello World", "", 11), "Hello World"))
    	test_ok("Empty needle", ft_strnstr("Hello World", "", 11));
	else
    	test_ko("Empty needle", ft_strnstr("Hello World", "", 11));
    if (ft_strnstr("Hello", "Hello World", 6) == NULL)
    	test_ok("Wrong compare 2", "null");
	else
    	test_ko("Wrong compare 2", "null");
}

void    ft_atoi_test(void)
{
    printf("\n------------ft_atoi--------------\n");
    if (ft_atoi("\t\v\f\r\n  +13h45") == 13)
    	test_ok("Test1", "13");
	else
    	test_ko("Test1", "13");
    if (ft_atoi("\n  -13hgh") == -13)
    	test_ok("Test2", "-13");
	else
    	test_ko("Test2", "-13");
    if (ft_atoi("\n\t\r  --13hgh") == 0)
    	test_ok("Test3", "0");
	else
    	test_ko("Test3", "0");
    if (ft_atoi("+2147483647t") == 2147483647)
    	test_ok("Test4", "int max");
	else
    	test_ko("Test4", "int max");
    if (ft_atoi("-2147483648t") == -2147483648)
    	test_ok("Test4", "int min");
	else
    	test_ko("Test4", "int min");
    if (ft_atoi("") == 0)
    	test_ok("Test4", "0");
	else
    	test_ko("Test4", "0");
}

void    ft_calloc_test(void)
{
    printf("\n------------ft_calloc--------------\n");
    if (mem_alloc_check(ft_calloc(0, 0), 1) == 1)
        test_ok("Zero mem allocation test", "0");
    else
        test_ko("Zero mem allocation test", "0");
    if (mem_alloc_check(ft_calloc(10, 8), 80) == 80)
        test_ok("80 bytes allocation test", "80");
    else
        test_ko("80 bytes allocation test", "80");
    if (ft_calloc(100000000, 1000000000) == NULL)
    	test_ok("Large memory", "null");
	else
    	test_ko("Large memory", "null");
}

void    ft_strdup_test(void)
{
    char    *mem;

    printf("\n------------ft_strdup--------------\n");
    mem = ft_strdup("Hello World");
    if (!strcmp(mem, "Hello World"))
    	test_ok("Test1", mem);
	else
    	test_ko("Test1", mem);
    free(mem);
    mem = ft_strdup("");
    if (!strcmp(mem, ""))
    	test_ok("Empty str", mem);
	else
    	test_ko("Empty str", mem);
    free(mem);
}


void    ft_substr_test(void)
{
    char    *substr;

    printf("\n------------ft_substr--------------\n");
    substr = ft_substr("Hello World", 2, 6);
    if (!strcmp(substr, "llo Wo"))
    	test_ok("Test1", substr);
	else
    	test_ko("Test1", substr);
    free(substr);
    substr = ft_substr("Hello World", 6, 10);
    if (!strcmp(substr, "World"))
    	test_ok("Test1", substr);
	else
    	test_ko("Test1", substr);
    free(substr);
    substr = ft_substr("Hello World", 12, 16);
    if (!strcmp(substr, ""))
    	test_ok("Empty str", substr);
	else
    	test_ko("Empty str", substr);
    free(substr);
}

void    ft_strjoin_test(void)
{
    char    *cpy;

    printf("\n------------ft_strjoin--------------\n");
    cpy = ft_strjoin("Hello ", "World");
    if (!strcmp(cpy, "Hello World"))
    	test_ok("Test1", cpy);
	else
    	test_ko("Test1", cpy);
    free(cpy);
    cpy = ft_strjoin("Hello", "");
    if (!strcmp(cpy, "Hello"))
    	test_ok("Test2", cpy);
	else
    	test_ko("Test2", cpy);
    free(cpy);
    cpy = ft_strjoin("", "Hello");
    if (!strcmp(cpy, "Hello"))
    	test_ok("Test3", cpy);
	else
    	test_ko("Test3", cpy);
    free(cpy);
    cpy = ft_strjoin("", "");
    if (!strcmp(cpy, ""))
    	test_ok("Test4", cpy);
	else
    	test_ko("Test4", cpy);
    free(cpy);
}

void    ft_strtrim_test(void)
{
    char    *cpy;

    printf("\n------------ft_strtrim--------------\n");
    cpy = ft_strtrim("\t Hello World  ", " \t");
    if (!strcmp(cpy, "Hello World"))
    	test_ok("Test1", cpy);
	else
    	test_ko("Test1", cpy);
    free(cpy);
    cpy = ft_strtrim("\t Hello World", " \t");
    if (!strcmp(cpy, "Hello World"))
    	test_ok("Test2", cpy);
	else
    	test_ko("Test2", cpy);
    free(cpy);
    cpy = ft_strtrim("Hello World  ", " \t");
    if (!strcmp(cpy, "Hello World"))
    	test_ok("Test3", cpy);
	else
    	test_ko("Test3", cpy);
    free(cpy);
    cpy = ft_strtrim("          ", " ");
    if (!strcmp(cpy, ""))
    	test_ok("Test4", cpy);
	else
    	test_ko("Test4", cpy);
    free(cpy);
}

void    ft_split_test(void)
{
    char    *verifier1[10] = {"Hello", "World", NULL};
    char    *verifier2[10] = {"He", "o Wor", "d", NULL};
    char    *verifier3[10] = {NULL};
    char    **str_arr;
    
    printf("\n------------ft_split--------------\n");
    str_arr = ft_split("Hello World", ' ');
    if (arr_of_strcmp(str_arr,  verifier1))
        test_ok("Test1", "Hello World");
	else
    	test_ko("Test1", "Hello World");
    for (int i = 0; str_arr[i]; i++)
        free(str_arr[i]);
    free(str_arr);
    str_arr = ft_split("Hello World", 'l');
    if (arr_of_strcmp(str_arr,  verifier2))
        test_ok("Test2", "Hello World");
	else
    	test_ko("Test2", "Hello World");
    for (int i = 0; str_arr[i]; i++)
        free(str_arr[i]);
    free(str_arr);
    str_arr = ft_split("      ", ' ');
    if (arr_of_strcmp(str_arr,  verifier3))
        test_ok("Test3", "      ");
	else
    	test_ko("Test3", "      ");
    for (int i = 0; str_arr[i]; i++)
        free(str_arr[i]);
    free(str_arr);
    str_arr = ft_split("   Hello World   ", ' ');
    if (arr_of_strcmp(str_arr,  verifier1))
        test_ok("Test4", "   Hello World   ");
	else
    	test_ko("Test4", "   Hello World   ");
    for (int i = 0; str_arr[i]; i++)
        free(str_arr[i]);
    free(str_arr);
}

void    ft_itoa_test(void)
{
    char    *num;

    printf("\n------------ft_itoa--------------\n");
    num = ft_itoa(13);
    if (strcmp(num, "13") == 0)
    	test_ok("Test1", "13");
	else
    	test_ko("Test1", "13");
    free(num);
    num = ft_itoa(-13);
    if (strcmp(num, "-13") == 0)
    	test_ok("Test2", "-13");
	else
    	test_ko("Test2", "-13");
    free(num);
    num = ft_itoa(0);
    if (strcmp(num, "0") == 0)
    	test_ok("Test3", "0");
	else
    	test_ko("Test3", "0");
    free(num);
    num = ft_itoa(-2147483648);
    if (strcmp(num, "-2147483648") == 0)
    	test_ok("Test4", "int min");
	else
    	test_ko("Test4", "int min");
    free(num);
}

void    ft_strmapi_test(void)
{
    char    *strmap;

    printf("\n------------ft_split--------------\n");
    strmap = ft_strmapi("Hello World", str_toupper);
    if (strcmp(strmap,  "HELLO WORLD") == 0)
        test_ok("Test1", strmap);
	else
    	test_ko("Test1", strmap);
    free(strmap);
    strmap = ft_strmapi("   a1   ", str_toupper);
    if (strcmp(strmap,  "   A1   ") == 0)
        test_ok("Test2", strmap);
	else
    	test_ko("Test2", strmap);
    free(strmap);
}

void    ft_striteri_test(void)
{
    char    str1[12] = "HEllo WorlD";
    char    str2[9] = "   B1   ";

    printf("\n------------ft_split--------------\n");
    ft_striteri(str1, str_tolower);
    if (strcmp(str1,  "hello world") == 0)
        test_ok("Test1", str1);
	else
    	test_ko("Test1", str1);
    ft_striteri(str2, str_tolower);
    if (strcmp(str2, "   b1   ") == 0)
        test_ok("Test2", str2);
	else
    	test_ko("Test2", str2);
}

void    ft_putchar_fd_test()
{
    char    data[2];
    char    c = 'f';
    int     fd;

	fd = open("test_fd", O_RDWR);
	ft_putchar_fd(c, fd);
    close(fd);

	fd = open("test_fd", O_RDONLY);
    read(fd, data, 2);
    close(fd);
    printf("\n------------ft_putchar_fd--------------\n");
    if (strncmp(data,  "f", 1) == 0)
        test_ok("Test1", data);
	else
    	test_ko("Test1", data);
}

void    ft_putstr_fd_test(void)
{
    char    data[6];
    char    *str = "Hello";
    int     fd;

	fd = open("test_fd", O_RDWR);
	ft_putstr_fd(str, fd);
    close(fd);
	fd = open("test_fd", O_RDONLY);
    read(fd, data, 6);
    close(fd);
    printf("\n------------ft_putstr_fd--------------\n");
    if (strncmp(data, str, 5) == 0)
        test_ok("Test1", data);
	else
    	test_ko("Test1", data);
}

void    ft_putendl_fd_test(void)
{
    char    data[7];
    char    *str = "Hello";
    int     fd;

	fd = open("test_fd", O_RDWR);
	ft_putendl_fd(str, fd);
    close(fd);
	fd = open("test_fd", O_RDWR);
    read(fd, data, 7);
    close(fd);
    printf("\n------------ft_putendl_fd--------------\n");
    if (strncmp(data, "Hello\n", 6) == 0)
        test_ok("Test1", data);
	else
    	test_ko("Test1", data);
}

void    ft_putnbr_fd_test(void)
{
    char    data[7];
    int     fd;

	fd = open("test_fd", O_RDWR);
	ft_putnbr_fd(-12345, fd);
    close(fd);
	fd = open("test_fd", O_RDWR);
    read(fd, data, 7);
    close(fd);
    printf("\n------------ft_putnbr_fd--------------\n");
    if (strncmp(data, "-12345", 6) == 0)
        test_ok("Test1", data);
	else
    	test_ko("Test1", data);
}

int main(void)
{
    int fd;

    fd = open("test_fd", O_CREAT);
    close(fd);

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
    ft_strlcat_test();
    ft_toupper_test();
    ft_tolower_test();
    ft_strchr_test();
    ft_strrchr_test();
    ft_strncmp_test();
    ft_memchr_test();
    ft_memcmp_test();
    ft_strnstr_test();
    ft_atoi_test();
    ft_calloc_test();
    ft_strdup_test();

    ft_substr_test();
    ft_strjoin_test();
    ft_strtrim_test();
    ft_split_test();
    ft_itoa_test();
    ft_strmapi_test();
    ft_striteri_test();
    ft_striteri_test();
    ft_putchar_fd_test();
    ft_putstr_fd_test();
    ft_putendl_fd_test();
    ft_putnbr_fd_test();

    return (0);
}