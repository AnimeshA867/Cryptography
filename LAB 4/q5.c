#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate GCD
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

// Function to perform modular exponentiation
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod)
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

// Function to generate RSA keys
void rsa_keygen(unsigned long long *n, unsigned long long *e, unsigned long long *d, unsigned long long p, unsigned long long q)
{
    *n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);
    *e = 2;
    while (*e < phi && gcd(*e, phi) != 1)
    {
        (*e)++;
    }
    unsigned long long k = 1;
    while ((1 + k * phi) % *e != 0)
    {
        k++;
    }
    *d = (1 + k * phi) / *e;
}

// Function to encrypt a message
unsigned long long rsa_encrypt(unsigned long long m, unsigned long long e, unsigned long long n)
{
    return mod_exp(m, e, n);
}

// Function to decrypt a message
unsigned long long rsa_decrypt(unsigned long long c, unsigned long long d, unsigned long long n)
{
    return mod_exp(c, d, n);
}

int main()
{
    unsigned long long p = 61; // First prime number
    unsigned long long q = 53; // Second prime number
    unsigned long long n, e, d;

    rsa_keygen(&n, &e, &d, p, q);

    printf("Public key: (n = %llu, e = %llu)\n", n, e);
    printf("Private key: (d = %llu)\n", d);

    unsigned long long message;
    printf("Enter message to encrypt (as a number): ");
    scanf("%llu", &message);

    unsigned long long encrypted_message = rsa_encrypt(message, e, n);
    printf("Encrypted message: %llu\n", encrypted_message);

    unsigned long long decrypted_message = rsa_decrypt(encrypted_message, d, n);
    printf("Decrypted message: %llu\n", decrypted_message);

    return 0;
}
