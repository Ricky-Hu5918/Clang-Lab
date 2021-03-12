#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func1(int **p)
{
    *p = (int *)malloc(4); //解引用了，是给p分配内存
    printf("in func1, p= %d\n", *p);
}

int func2(int *p)
{
    p = (int *)malloc(sizeof(int)); //没有解引用，是给p的地址分配内存
    printf("in func2, p= %d\n", p);
}

int main(void)
{
    int *p;
    int *q;

    func1(&p);
    printf("after func1 p= %d\n", p);

    func2(&q);
    printf("after func2 q= %d\n", q);
    printf("after func2 q= %d\n", &q);

    return 0;
}