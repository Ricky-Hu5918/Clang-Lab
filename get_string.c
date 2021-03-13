/*
differences among getchar, scanf, gets
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char str[20];
    int i = 0;

    //getchar：接收单个字符
    while ((str[i] = getchar()) != '\n') //接受空格和其它字符，以回车结束输入
    {
        i++;
    }
    str[i] = '\0';
    printf("getchar output: %s \n", str);

    fflush(stdin);
    //scanf：接收字符串，不含空格
    scanf("%s", str); //不接受空格，遇空格或回车结束输入，输出空格前内容
    printf("scanf output: %s \n", str);

    fflush(stdin);
    //使用scanf每次读入一个字符，直到遇到回车结束输入，可以读取空格和其它字符，类似于getchar的用法
    do
    {
        scanf("%c", &str[i]);
    } while (str[i++] != '\n');
    str[i] = '\0';
    printf("scanf output22: %s \n", str);

    fflush(stdin);
    //gets：接收字符串，含空格
    gets(str); //接受空格和其它字符，以回车结束输入
    printf("gets output: %s \n", str);

    return 0;
}