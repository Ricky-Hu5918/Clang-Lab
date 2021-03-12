/*编写一个函数，从标准输入读取一列整数，把这些值存储在一个动态分配的数组中并返回这个数组。
函数通过观察EOF判断输入列表是否结束。数组的第一个数是数组包含的值的个数，它的后面就是这些整数值。*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 10
int *readinput_num(void)
{
    int *arry;
    int size = MAX_SIZE;
    int count;
    int value;

    arry = (int *)malloc((size + 1) * sizeof(int));
    if (arry == NULL)
    {
        printf("arry malloc failed. \n");
        return NULL;
    }
    memset(arry, 0, size);

    count = 0;
    while (scanf("%d", &value) == 1)
    {
        count += 1;
        if (count > size) //need more space to store value
        {
            printf("count > size. \n");
            size += MAX_SIZE;
            arry = realloc(arry, (size + 1) * sizeof(int));
            if (arry == NULL)
            {
                printf("arry remalloc failed. \n");
                return NULL;
            }
        }

        arry[count] = value; //store value from index 1
    }

    if (count < size)
    {
        arry = realloc(arry, (count + 1) * sizeof(int));
        if (arry == NULL)
        {
            printf("count<size, realloc failed! \n");
            return NULL;
        }
    }

    arry[0] = count;

    return arry;
}

int main(void)
{
    int *p = NULL;
    int i;

    p = readinput_num();
    printf("<---address of p: %d\n", p);

    for (i = 0; i < p[0] + 1; i++)
    {
        printf(" %d ", p[i]);
    }
    printf("\n arry has been outputed. \n");

    free(p);
    p = NULL;
    printf("--->address of p: %d\n", p);

    return 0;
}