#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
memset()是以字节为单位进行赋值的，所以一定要注意赋值的对象的类型。
char占一个字节，int占4个字节，double占8个字节
所以推荐使用：memset(dest, data, number * sizeof(type))
*/
int main(void)
{
    char a[5];
    int i;

    //memset(a, '1', 5);
    memset(a, '1', 5 * sizeof(char));
    for (i = 0; i < 5; i++)
    {
        printf("char: %c ", a[i]);
    }

    int b[5];
    //memset(b, 1, 5); //试图给int型数字赋值，实际只完成了5个字节，对应着数组中的1个元素
    //memset(b, 1, 20); //5个int元素占20个字节, 推荐使用sizeof(int)
    memset(b, 1, 5 * sizeof(int));
    for (i = 0; i < 5; i++)
    {
        printf("\n int: %d", b[i]); //一个int变量占4个字节，给这4个字节分别赋值为1，因此二进制是00000001 00000001 00000001 00000001
                                    //对应的十进制为16843009，即为输出结果
    }

    return 0;
}
