#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sq(int c)
{
    //c * c;
}

int fun(int c)
{
    //int c = 8; //Error: redefiniiton of c
    c = 6;
    return c * c;
}

int main()
{
    int a = 8, b;
    b = sq(a);
    printf("%d", b);

    b = fun(a);
    printf("\n %d \n", b);

    char c[] = "hel";         //字符串存储时会在末尾添加一个'\0'，所以此时c占用4个字节。字符串以'\0'作为停止符，strcpy()/strcat()遇到\0会停止
    printf("%lu", sizeof(c)); //output: 4 但是strlen()不会将\0及其后面的字符计入字符串长度

    char e[] = "he\0llo";
    printf("\n %lu", strlen(e)); //output: 2, strlen()不会将\0及其后面的字符计入字符串长度

    char d[5] = "hello";
    memset(d, '\0', 5);
    printf("\n %s \n", d); //output: nothing 因为memset已经将字符数组d清空了

    int f = 10;
    {
        int f = 12;
        printf("%d \n", f); //output: 12
    }

    // int g = 9;
    // if (g < 2)
    // {
    //     int h;
    //     h = 5;
    // }
    // printf("%d\n", h); //Error: h is undefined

    int i = 7;
    printf("\n%d %d\n", ++i, ++i);

    //sizeof不是运算符，它只取变量类型，所以无论sizeof后面是否有括号，或括号内是否有运算，均忽略
    int j = 0;
    int sizeint;
    sizeint = sizeof j++;
    printf("%d \n", j); //output: 0

    sizeint = sizeof(++j);
    printf("%d %d\n", j, sizeint); //output: 0 4 or be manchine dependent

    a = 10;
    b = 20;
    j = 5;
    int k;
    k = a < b < j;
    printf("%d\n", k); //output: 1. 执行顺序是(a<b)<j = (10<20)<5 = 1<5 = 1

    int l[3] = {1, 2, 3};
    printf("%d \n", l[3]);
    printf("%d \n", l[-1]);

    printf("%c\n", 5 ["helloworld"]);

    int m = 10;
    // for (;;;) //Error, it should be for(;;)
    //     printf("%d", m++);

    for (; m;)
    {
        printf("%d", m--); //output: 10987654321
    }

    static int n = 3;
    {
        n = 5;
    }
    printf("\n static n = %d \n", n);

    return 0;
}