#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将字符串内容反转输出
int main(void)
{
    char *src = "Hello, world!";
    char *dest = NULL;
    int len = 0;

    len = strlen(src);
    dest = (char *)malloc(len + 1);
    if (dest == NULL)
    {
        printf("dest malloc failed. \n");
        return -1;
    }
    printf("dest1: %d len: %d \n", dest, len);

    char *p = dest;
    //strncpy(dest, src, len); //把src所指向的字符串复制到dest，最多复制n个字符

    while (len-- != 0)
    {
        *dest++ = src[len];
    }
    //*dest = 0;
    printf("string dest: %s \n", p);
    printf("before &p: %d\n", &p);    //p的地址
    printf("befor &*p: %d\n", &(*p)); //dest的地址

    //此处不能释放dest，因为dest++了，所以dest已经指向了申请的内存空间的最末端，而不是首地址
    if (p != NULL)
    {
        printf("Free p! \n");
        free(p);
        p = NULL;
    }

    //free(dest - 13);
    printf("string dest: %s \n", p);

    return 0;
}