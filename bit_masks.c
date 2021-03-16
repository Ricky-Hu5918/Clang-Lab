/*
给定一个整型变量a，写两段代码，第一个设置a的bit 3，第二个清除a 的bit 3。在以上两个操作中，要保持其它位不变。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT3 (0x1 << 3)

int set_bit3(int *a)
{
    *a |= BIT3;
    return *a;
}

int clear_bit3(int *a)
{
    *a &= ~BIT3;
    return *a;
}

int main(void)
{
    int a = 5;
    a = set_bit3(&a);
    printf("set_bit: %d \n", a);

    a = clear_bit3(&a);
    printf("clear_bit: %d \n", a);

    return 0;
}