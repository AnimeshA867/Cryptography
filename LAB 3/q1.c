// 1) WAP to implement the Euclidean Algorithm (GCD)

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

int main()
{
    int a, b;
    printf("Enter the value of a and b respectively:");
    scanf("%d %d", &a, &b);
    printf("The gcd of %d and %d is %d\n", a, b, gcd(a, b));
    printf("Program by Animesh Acharya.");
    return 0;
}