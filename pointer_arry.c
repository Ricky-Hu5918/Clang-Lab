/*
指针数组：数组的每一个元素都是指针。指针元素可以指向任意变量，包括int或字符串。
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int a = 3, b = 5, c = 7;
    int i, j;
    int str_sub_len;

    int *arry[] = {&a, &b, &c}; //指针元素是int变量
    int len = sizeof(arry) / sizeof(arry[0]);
    printf("len = %d \n", len);

    for (i = 0; i < len; i++)
    {
        printf("%d ", arry[i]);    //address
        printf("%d \n", *arry[i]); //value
    }

    char *str[] = {"hello world!", "welcome to", "Canada"}; //指针元素是字符串
    int str_len = sizeof(str) / sizeof(str[0]);
    printf("\nstr_len = %d\n", str_len);

    for (i = 0; i < str_len; i++)
    {
        printf("\n%s ", str[i]);  //address, 因为是字符串，所以首地址即可输出全部字符串，而不是*str[i]
        printf("%c \n", *str[i]); //value, *str[i]输出的是每个字符串的首字母

        str_sub_len = strlen(str[i]);
        printf("\n #%d str_sub_len = %d \n", i, str_sub_len);

        for (j = 0; j < str_sub_len; j++)
        {
            printf("%c", *(str[i] + j)); //value, 通过解引用取单个字符的方式获取整个字符串的值
        }
    }

    return 0;
}