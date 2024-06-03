#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenere_cipher_encrypt(char *text, char *key)
{
    int key_length = strlen(key);
    int i = 0;
    while (*text != '\0')
    {
        if (isalpha(*text))
        {
            char base = islower(*text) ? 'a' : 'A';
            *text = ((*text - base + tolower(key[i % key_length]) - 'a') % 26) + base;
            i++;
        }
        text++;
    }
}

int main()
{
    char text[] = "ANIMESH ACHARYA";
    char key[] = "key";

    printf("Original text: %s\n", text);

    vigenere_cipher_encrypt(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}
