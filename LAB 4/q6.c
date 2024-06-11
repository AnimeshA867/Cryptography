// Implement Elgamal cryptographic system

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned long long
mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

unsigned long long generate_prime()
{
    return 7879;
}

unsigned long long find_primitive_root(unsigned long long p)
{
    for (unsigned long long g = 2; g < p; g++)
    {
        bool found = true;
        for (unsigned long long i = 1; i < p - 1; i++)
        {
            if (mod_exp(g, i, p) == 1 && i != p - 1)
            {
                found = false;
                break;
            }
        }
        if (found)
            return g;
    }
    return -1;
}

void elgamal_keygen(unsigned long long *p, unsigned long long *g, unsigned long long *x, unsigned long long *y)
{
    *p = generate_prime();
    *g = find_primitive_root(*p);
    *x = rand() % (*p - 2) + 1;
    *y = mod_exp(*g, *x, *p);
}

void elgamal_encrypt(unsigned long long p, unsigned long long g, unsigned long long y, unsigned long long m, unsigned long long *c1, unsigned long long *c2)
{
    unsigned long long k = rand() % (p - 2) + 1;
    *c1 = mod_exp(g, k, p);
    *c2 = (mod_exp(y, k, p) * m) % p;
}

unsigned long long elgamal_decrypt(unsigned long long p, unsigned long long x, unsigned long long c1, unsigned long long c2)
{
    unsigned long long s = mod_exp(c1, x, p);
    unsigned long long s_inv = mod_exp(s, p - 2, p);
    return (c2 * s_inv) % p;
}

int main()
{

    unsigned long long p, g, x, y;
    elgamal_keygen(&p, &g, &x, &y);
    printf("Public key (p, g, y): (%llu, %llu, %llu)\n", p, g, y);
    printf("Private key (x): %llu\n", x);

    unsigned long long m;
    printf("Enter message to encrypt (as a number): ");
    scanf("%llu", &m);

    unsigned long long c1, c2;
    elgamal_encrypt(p, g, y, m, &c1, &c2);
    printf("Encrypted message (c1, c2): (%llu, %llu)\n", c1, c2);

    unsigned long long decrypted_message = elgamal_decrypt(p, x, c1, c2);
    printf("Decrypted message: %llu\n", decrypted_message);
    printf("Program by Animesh Acharya \n");

    return 0;
}
