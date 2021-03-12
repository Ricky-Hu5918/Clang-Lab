#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *func1(void)
{
    char *p1 = (char *)malloc(sizeof(char));
    printf("func1 p1= %d\n", p1);
    return p1;
}

void func2(char **p2)
{
    printf("func2 p2= %d\n", *p2);
    if (*p2 != NULL)
    {
        free(*p2);
        *p2 = NULL;
    }
    printf("func2 after free. p2= %d\n", *p2);
}

void func3(char *p3)
{
    printf("func3 p3= %d\n", p3);
    if (p3 != NULL)
    {
        free(p3);
        p3 = NULL;
    }
    printf("func3 after free. p3= %d\n", p3);
}

int main(void)
{
    char *p;
    p = func1();
    printf("main p= %d\n", p);

    //func2(&p); //地址传递，内存会释放掉，同时会修改main函数中的p值

    func3(p); //类似于值传递，在func3()中会释放掉内存，但是main函数中的p不会改变
    printf("main after free p= %d\n", p);
    return 0;
}