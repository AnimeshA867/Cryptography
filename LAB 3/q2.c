// 2) WAP to find additive inverse

#include <stdio.h>

int additiveInverse(int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if ((x + i) % n == 0)
        {
            return i;
        }
    }
}

int main()
{
    int n, x;
    printf("Enter a number:");
    scanf("%d", &x);
    printf("Enter the modulo:");
    scanf("%d", &n);
    printf("The additive inverse of %d over modulo %d is %d \n", x, n, additiveInverse(n, x));
    printf("Program by Animesh Acharya.");

    return 0;
}