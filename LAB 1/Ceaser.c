#include <stdio.h>

void caesar_cipher(char *text, int shift)
{
    while (*text)
    {
        if ((*text >= 'A' && *text <= 'Z') || (*text >= 'a' && *text <= 'z'))
        {
            if (*text >= 'A' && *text <= 'Z')
                *text = ((*text - 'A' + shift) % 26) + 'A';
            else
                *text = ((*text - 'a' + shift) % 26) + 'a';
        }
        text++;
    }
}

int main()
{
    char plain_text[] = "ANIMESH ACHARYA";
    int shift = 3;
    printf("Unencrypted: %s\n", plain_text);
    caesar_cipher(plain_text, shift);
    printf("Encrypted: %s\n", plain_text);
    return 0;
}
