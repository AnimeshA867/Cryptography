// 4) WAP to verify if two numbers are relatively prime of not.

#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}

int relativePrime(int a, int b)
{
    if (gcd(a, b) == 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int a, b;
    printf("Enter the value of a and b respectively:");
    scanf("%d %d", &a, &b);
    if (relativePrime(a, b))
        printf("%d and %d are relatively prime\n", a, b);
    else
        printf("%d and %d are not relatively prime\n", a, b);
    printf("Program by Animesh Acharya.");

    return 0;
}
