// 3) WAP to find the multiplicative inverse.

#include <stdio.h>
void extendedEuclidean(int x, int m)
{
    if (x > m)
    {
        int temp = x;
        x = m;
        m = temp;
    }
    printf("q\t r1\t r2\t r\t t1\t t2\t t\n");
    int q, r1, r2, t1, t2, r, t;
    r1 = m;
    r2 = x;
    t1 = 0;
    t2 = 1;
    while (r2 != 0)
    {
        q = r1 / r2;
        r = r1 % r2;
        t = t1 - q * t2;
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\n", q, r1, r2, r, t1, t2, t);
        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }
    printf("The multiplicative inverse is %d\n", t1);
}

int main()
{
    int x, n;
    printf("Enter a number:");
    scanf("%d", &x);
    printf("Enter the modulo:");
    scanf("%d", &n);

    extendedEuclidean(x, n);
    printf("Program by Animesh Acharya.");

    return 0;
}