// Second less comfortable pset2 exercise (vigenere) | This program improves the caesar encryption, using letters this time
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
        printf("A error has been ocurred: The usage should be like ./vigenere ABC\n");
        return 1;
    }
    // Check if the argument is an alphabetic value, if not it raises a error
    string keyword = argv[1];
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("A error has been ocurred: You input a non alphabetic value as argument, please try again using a valid key\n");
            return 1;
        }
    }
    // Prompts the user to input the plaintext string
    string plainText = get_string("plaintext: ");
    // Encipher process
    int sum;
    int index;
    int counter = 0;
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        // The counter is used iterate over the keyword letters, If the counter exceed the lenght of the value, then it starts over
        if (counter >= strlen(keyword))
        {
            counter = 0;
        }
        if (isalpha(plainText[i]))
        {
            if (isupper(keyword[counter]))
            {
                index = keyword[counter] - 65;
            }
            else
            {
                index = keyword[counter] - 97;
            }
            counter++;
        }

        // Change each plainText letter value depending if it's upper or lower
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                sum = (index + (plainText[i] - 65)) % 26;
                printf("%c", sum + 65);
            }
            else if (islower(plainText[i]))
            {
                sum = (index + (plainText[i] - 97)) % 26;
                printf("%c", sum + 97);
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