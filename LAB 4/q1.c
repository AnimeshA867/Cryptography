#include <stdio.h>

// Function to calculate the GCD of two numbers
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    while (b != 0)
    {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate Euler's Totient Function
unsigned long long euler_totient(unsigned long long n)
{
    unsigned long long count = 0;
    for (unsigned long long i = 1; i < n; i++)
    {
        if (gcd(n, i) == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    unsigned long long n;
    printf("Enter a number: ");
    scanf("%llu", &n);
    printf("Euler's Totient Function φ(%llu) = %llu\n", n, euler_totient(n));
    printf("Program by Animesh Acharya \n");
    return 0;
}
