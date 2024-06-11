//Implement RSA algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime
    if (n <= 3) return 1; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0; // multiples of 2 and 3 are not prime
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate a prime number
int generate_prime_number() {
    int prime_candidate = 23; // Start with a candidate prime number
    while (!is_prime(prime_candidate)) {
        prime_candidate++;
    }
    return prime_candidate;
}

// Function to calculate greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to generate public and private keys
void generate_key_pair(int *public_key, int *private_key, int *n) {
    int p = generate_prime_number();
    int q = generate_prime_number();
    *n = p * q; // Compute n
    int phi = (p - 1) * (q - 1); // Compute Euler's totient function
    int e = 2; // Public exponent
    while (e < phi) {
        if (gcd(e, phi) == 1) // Ensure e is coprime with phi
            break;
        e++;
    }
    *public_key = e;
    *private_key = mod_inverse(e, phi); // Calculate private key
}

// Function to encrypt a message using public key
int encrypt(int message, int public_key, int n) {
    return power_modulo(message, public_key, n);
}

// Function to decrypt a ciphertext using private key
int decrypt(int ciphertext, int private_key, int n) {
    return power_modulo(ciphertext, private_key, n);
}

// Function to calculate modular exponentiation
int power_modulo(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int public_key, private_key, n;

    // Generate public and private keys
    generate_key_pair(&public_key, &private_key, &n);

    // Message to be encrypted
    int message = 123;

    // Encrypt the message using the public key
    int encrypted_message = encrypt(message, public_key, n);
    printf("Encrypted Message: %d\n", encrypted_message);

    // Decrypt the encrypted message using the private key
    int decrypted_message = decrypt(encrypted_message, private_key, n);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}
