#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void createPlayfairMatrix(char key[], char matrix[][SIZE])
{
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int i, j, k, len, keyLen;

    len = strlen(key);
    keyLen = 0;

    for (i = 0; i < len; i++)
    {
        if (!isspace(key[i]))
        {
            key[keyLen] = toupper(key[keyLen]);
            if (key[keyLen] == 'J')
                key[keyLen] = 'I';
            keyLen++;
        }
    }
    key[keyLen] = '\0';
    strcat(alphabet, key);
    len = strlen(alphabet);
    k = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            matrix[i][j] = alphabet[k];
            k++;
        }
    }
}
void playfair_cipher_encrypt(char matrix[][SIZE], char *text)
{
    int i, r1, r2, c1, c2;
    while (*text != '\0')
    {
        if (isalpha(*text))
        {
            char ch1 = toupper(*text);
            char ch2 = toupper(*(text + 1));
            int j, k;
            for (i = 0; i < SIZE; i++)
            {
                for (j = 0; j < SIZE; j++)
                {
                    if (matrix[i][j] == ch1)
                    {
                        r1 = i;
                        c1 = j;
                    }
                    if (matrix[i][j] == ch2)
                    {
                        r2 = i;
                        c2 = j;
                    }
                }
            }
            if (r1 == r2)
            {
                *text = matrix[r1][(c1 + 1) % SIZE];
                *(text + 1) = matrix[r2][(c2 + 1) % SIZE];
            }
            else if (c1 == c2)
            {
                *text = matrix[(r1 + 1) % SIZE][c1];
                *(text + 1) = matrix[(r2 + 1) % SIZE][c2];
            }
            else
            {
                *text = matrix[r1][c2];
                *(text + 1) = matrix[r2][c1];
            }
            text += 2;
        }
        else
        {
            text++;
        }
    }
}
int main()
{
    char key[] = "KEYWORD";
    char text[] = "ANIMESHACHARYA";
    char matrix[SIZE][SIZE];
    createPlayfairMatrix(key, matrix);
    printf("Original text: %s\n", text);
    playfair_cipher_encrypt(matrix, text);
    printf("Encrypted text: %s\n", text);
    return 0;
}
