#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Rail Fence Cipher
void railFenceCipher(char *plaintext, int rails)
{
    int len = strlen(plaintext);
    char railMatrix[rails][len]; // Corrected: Second dimension should be len
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            railMatrix[i][j] = '\0'; // Corrected: Initialize with null character

    int dir_down = 0;
    int row = 0, col = 0;

    for (int i = 0; i < len; i++)
    {
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;

        railMatrix[row][col++] = plaintext[i];

        dir_down ? row++ : row--;
    }

    // Print the rail matrix
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (railMatrix[i][j] != '\0') // Corrected: Check for null character
                printf("%c", railMatrix[i][j]);

    printf("\n");
}

int main()
{
    char plaintext[100], key[100];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Corrected: Remove newline character

    printf("Enter the number of rails for Rail Fence Cipher: ");
    scanf("%d", &rails);

    printf("Rail Fence Cipher: ");
    railFenceCipher(plaintext, rails);

    return 0;
}
