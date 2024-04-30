#include <stdio.h>

#define N 3

void hill_cipher_encrypt(int key[][N], char *text)
{
    int i, j, k, sum;
    while (*text != '\0')
    {
        if (isalpha(*text))
        {
            int vector[N] = {tolower(text[0]) - 'a', tolower(text[1]) - 'a', tolower(text[2]) - 'a'};
            for (i = 0; i < N; i++)
            {
                sum = 0;
                for (j = 0; j < N; j++)
                {
                    sum += key[i][j] * vector[j];
                }
                text[i] = (sum % 26) + 'a';
            }
            text += N;
        }
        else
        {
            text++;
        }
    }
}

int main()
{
    char text[] = "hello";
    int key[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Original text: %s\n", text);

    hill_cipher_encrypt(key, text);

    printf("Encrypted text: %s\n", text);

    return 0;
}
