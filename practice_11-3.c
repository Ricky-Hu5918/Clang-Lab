/*编写一个函数， 从标准输入读取一个字符串，把字符串复制到动态分配的内存中，并返回该字符串的拷贝
这个函数不应该对读入字符串的长度做任何限制！*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

//read string from standard input
char *readinput_str(void)
{
    char *buff = NULL;
    int buff_len = 0;
    int input_str_len = 0;

    char *ptr = buff;
    int ch;

    //从标准输入逐个读入字符getchar(), 并强制转换为int
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (input_str_len >= buff_len)
        {
            printf("apply new memory! \n");
            buff_len += MAX_SIZE;
            buff = realloc(buff, buff_len); // 每次新增10个字节的空间
            ptr = buff + input_str_len;     //让ptr指向刚新增内存的地方
        }
        input_str_len++;
        *ptr++ = ch;
    }

    return buff;
}

//copy string
char *mystr_cpy(char const *string)
{
    char *new_string = NULL;

    new_string = (char *)malloc((strlen(string) + 1) * sizeof(char));
    if (new_string == NULL)
    {
        printf("new_string malloc failed. \n");
        return NULL;
    }

    strcpy(new_string, string);

    if (string != NULL)
    {
        free(string);
        string = NULL;
    }

    return new_string;
}

int main(void)
{
    char *p = NULL;

    //p = readinput_str();
    p = mystr_cpy(readinput_str());
    printf("The input string is: %s\n", p);

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}