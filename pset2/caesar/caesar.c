// First less comfortable pset2 exercise (caesar) | This program encipher alphabetic strings shifting the letters with a key
// Marcelo Díaz, CS50x Harvard's course

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // If the program execution have more or less than two arguments then it raises a error
    if (argc != 2)
    {
        printf("A error has been ocurred: You should put a numeric key as argument (just one argument)\n");
        return 1;
    }
    // Check if the argument is a numeric value, if not it raises a error
    string s = argv[1];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            printf("A error has been ocurred: You input a non numeric value as argument, please try using a valid key\n");
            return 1;
        }
    }
    // Declares the variable key
    int key = atoi(argv[1]);
    if (key < 1)
    {
        printf("A error has been ocurred: You input a key value as argument that is less than 1, please try using a valid key\n");
        return 1;
    }
    // Prompts the user to input the plaintext string
    string plainText = get_string("Plaintext: ");

    // Declaration of lowercase and uppercase alphabet
    char lowerAlpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                           'v', 'w', 'x', 'y', 'z'
                          };
    char upperAlpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                           'V', 'W', 'X', 'Y', 'Z'
                          };
    // Encipher process
    int sum;
    int index;
    printf("ciphertext:");
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                index = plainText[i] - 65;
                sum = (index + key) % 26;
                printf("%c", upperAlpha[sum]);
            }
            else
            {
                index = plainText[i] - 97;
                sum = (index + key) % 26;
                printf("%c", lowerAlpha[sum]);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    return 0;
}