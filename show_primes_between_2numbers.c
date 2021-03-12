#include "stdio.h"

//check if the num is a prime, yes return 1, no return 0
int checkPrimenumber(int n)
{
    int i, flag = 1;

    for (i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

//show all primes between num1 and num2
int main()
{
    int n1, n2, i, flag;
    printf("please enter 2 integers: ");
    scanf("%d %d \n", &n1, &n2);

    if (n1 > n2)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    // printf("%d %d \n", n1, n2);

    for (i = n1 + 1; i < n2; i++)
    {
        flag = checkPrimenumber(i);
        if (flag == 1)
        {
            printf("%d is a prime. \n", i);
        }
    }
}