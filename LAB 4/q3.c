//  Impelement Miller's Algorithm for testing primality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned long long
power(unsigned long long x, unsigned long long y, unsigned long long p)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

bool millerTest(unsigned long long d, unsigned long long n)
{

    unsigned long long a = 2 + rand() % (n - 4);

    unsigned long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool isPrime(unsigned long long n, int k)
{

    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    unsigned long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main()
{
    unsigned long long num;
    int k = 4;
    printf("Enter a number: ");
    scanf("%llu", &num);

    if (isPrime(num, k))
        printf("%llu is a prime number.\n", num);
    else
        printf("%llu is not a prime number.\n", num);
    printf("Program by Animesh Acharya \n");

    return 0;
}
