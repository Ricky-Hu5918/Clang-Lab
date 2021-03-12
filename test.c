#include "stdio.h"

// void f(void **p);

// int k = 2;
// int *pk = &k;

// int main(void)
// {
//     int *p;
//     f((void **)&p);
//     printf("%d\n", *p);
//     return 0;
// }

// void f(void **pp)
// {
//     (*pk)++;
//     *pp = pk;
// }

// #include <stdio.h>
// #define PRODUCT(x) (x * x)
// int main(void)
// {
//     int i = 3, j;
//     j = PRODUCT(i + 2);
//     printf("%d %d\n", i, j);
//     return 0;
// }

// int main(void)
// {
//     // int a[5] = {5, 1, 15, 20, 25};
//     // int *p = &a[2];
//     // printf("%d\n", p[-1]);
//     unsigned short int k = 32768;
//     printf("%d", k);
//     unsigned long int l = 32768;
//     printf("l: %d", l);

//     long int j = 32768;
//     printf("%d", j);

//     short int i = 32768;
//     printf("i: %d", i);

//     char m = 32768;
//     printf("m: %d", m);

//     return 0;
// }
#include <stdlib.h>
#include <string.h>

// int main(void)
// {
//     char *s = "32";
//     long l = strtol(s, NULL, 0x10);
//     printf("%lu\n", l);

//     int c[1];
//     printf("c: %lu", sizeof(c));

//     printf("short: %lu int: %lu char: %lu unsigned int: %lu signed int: %lu long: %lu", sizeof(short), sizeof(int), sizeof(char), sizeof(unsigned int), sizeof(signed int), sizeof(long));
//     return 0;
// }

int main(void)
{
    int *p1 = NULL;
    int i;
    int arry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    p1 = malloc(10);

    if (p1 == NULL)
    {
        printf("p1 malloc failed. \n");
        return -1;
    }

    int len = sizeof(arry) / sizeof(arry[0]);
    printf("len = %d \n", len);

    int *p2 = p1;

    for (i = 0; i < len; i++)
    {
        *p1++ = arry[i];
        //p1[i] = arry[i];
    }

    // for (i = 0; i < 10; i++)
    // {
    //     printf("output: %d \n", *p2++);
    // }

    free(p2);
}