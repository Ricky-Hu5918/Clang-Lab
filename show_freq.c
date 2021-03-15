/*
读取范围在1和标准输入读取的size之间的每个数据出现的次数
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *frequency(int size)
{
    int *arry;
    int i;

    //arry = (int *)malloc(size * 2);
    //按需分配内存
    arry = (int *)calloc(size + 1, sizeof(int));
    if (arry == NULL)
    {
        printf("arry calloc failed. \n");
        return NULL;
    }

    //调整指针，让它后退一个整型位置，这样我们就可以使用范围1-size的下标
    //arry -= 1;  //释放内存会出错

    // //把各个元素值清零 --->使用calloc()时，会自动将内存设置为0
    // for (i = 0; i <= size; i += 1)
    // {
    //     arry[i] = 0;
    // }

    //计数每个值出现的次数，然后返回结果
    //从键盘读入一个数字，并将以该数字为下标的数组值+1，即为记录该数字被输入的次数
    printf("please input numbers from 1 to %d \n", size);
    while (scanf("%d", &i) != EOF)
    {
        arry[i] += 1;
    }

    //free(arry);

    printf("before return: %d\n", arry);
    return arry;
}

void freq_mem_free(int **p)
{
    if (*p != NULL)
    {
        printf("free p!!! \n");
        free(*p);
        *p = NULL;
    }
}

int main(void)
{
    int size;
    int *p;
    int i;

    printf("please input a number: \n ");
    scanf("%d", &size);

    p = frequency(size);

    for (i = 1; i <= size; i++)
        printf("The number %d occurs %d times. \n", i, p[i]);
    //printf("The number %d occurs %d times. \n", i, *(++p));

    printf("before release  p= %d\n", p);
    //释放之前申请的内存
    // free(p);
    // p = NULL;

    freq_mem_free(&p);

    // freq_mem_free(*p);
    printf("release mem! p= %d\n", p);
    // printf("release mem! *p= %d\n", *p);
}