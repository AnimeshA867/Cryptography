#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Row Transposition Cipher
void rowTranspositionCipher(char *plaintext, char *key)
{
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);
    int cols = keyLen;
    int rows = (textLen + keyLen - 1) / keyLen;
    char grid[rows][cols];
    int index = 0;

    // Fill grid with plaintext
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index < textLen)
                grid[i][j] = plaintext[index++];
            else
                grid[i][j] = ' ';
        }
    }

    // Rearrange grid columns according to key
    for (int i = 0; i < keyLen; i++)
    {
        int pos = key[i] - '0' - 1;
        for (int j = 0; j < rows; j++)
        {
            if (grid[j][pos] != ' ') // Print only non-empty characters
                printf("%c", grid[j][pos]);
        }
    }
    printf("\n");
}

int main()
{
    char plaintext[100], key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter the key for Row Transposition Cipher: ");
    scanf("%s", key);

    printf("Row Transposition Cipher: ");
    rowTranspositionCipher(plaintext, key);

    return 0;
}
