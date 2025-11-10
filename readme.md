To use static library libft:
    cc -Wall -Werror -Wextra -o test test.c -L. -lft 
    (remove lib and .a from the static library name Ex: libft.a -> ft)
    run: ./test

tester:
https://github.com/Tripouille/libftTester
git repo:
https://github.com/Tripouille/libftTester.git

function    test    mem-test
isalpha     ok      ok
isdigit     ok      ok
isanum      ok      ok
isascii     ok      ok
isprint     ok      ok
strlen      ok      ok
memset      ok      ok
bzero       ok      ok
memcpy      ok      ok
memmove     ok      ok
strlcpy     ok      ok
strlcat     ok      ok
toupper     ok      ok
tolower     ok      ok
strchr      ok      ok
strrchr     ok      ok
strncmp     ok      ok
strncmp     ok      ok
memchr      ok      ok
memcmp      ok      ok
strnstr     ok      ok
atoi        ok      ok
calloc      ok      ok
strdup      ok      ok

substr      ok      ok
strjoin     ok      ok
strtrim     ok      ok
split       ok      ok
itoa        ok      ok
strmapi     ok      ok
striteri    ok      ok
putchar_fd  ok      ok