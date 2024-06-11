// Implement Diffie-Hellman Key exchange

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n)
{
    if (n <= 1)
        return 0; // 0 and 1 are not prime
    if (n <= 3)
        return 1; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0)
        return 0; // multiples of 2 and 3 are not prime
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate a prime number
int generate_prime_number()
{
    int prime_candidate = 23; // Start with a candidate prime number
    while (!is_prime(prime_candidate))
    {
        prime_candidate++;
    }
    return prime_candidate;
}

// Function to generate a primitive root modulo prime
int generate_primitive_root(int prime)
{
    // For simplicity, let's assume a fixed primitive root
    return 5;
}

// Function to generate a private key
int generate_private_key(int prime)
{
    return rand() % (prime - 2) + 2; // Random number between 2 and prime-1
}

// Function to calculate modular exponentiation
int power_modulo(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// Function to generate a public key
int generate_public_key(int private_key, int prime, int primitive_root)
{
    return power_modulo(primitive_root, private_key, prime);
}

// Function to generate a shared secret
int generate_shared_secret(int private_key, int other_public_key, int prime)
{
    return power_modulo(other_public_key, private_key, prime);
}

int main()
{
    // Generate a prime number and primitive root
    int prime = generate_prime_number();
    int primitive_root = generate_primitive_root(prime);

    // Alice's side
    srand(time(NULL)); // Seed random number generator
    int alice_private_key = generate_private_key(prime);
    int alice_public_key = generate_public_key(alice_private_key, prime, primitive_root);
    printf("Alice's public key: %d\n", alice_public_key);

    // Bob's side
    int bob_private_key = generate_private_key(prime);
    int bob_public_key = generate_public_key(bob_private_key, prime, primitive_root);
    printf("Bob's public key: %d\n", bob_public_key);

    // Exchange public keys

    // Alice computes the shared secret
    int alice_shared_secret = generate_shared_secret(alice_private_key, bob_public_key, prime);
    printf("Alice's shared secret: %d\n", alice_shared_secret);

    // Bob computes the shared secret
    int bob_shared_secret = generate_shared_secret(bob_private_key, alice_public_key, prime);
    printf("Bob's shared secret: %d\n", bob_shared_secret);
    printf("Program by Animesh Acharya \n");

    return 0;
}
