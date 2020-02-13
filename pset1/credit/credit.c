// More comfortable pset1 exercise (credit) | This program validates a credit card number
// Marcelo Díaz, CS50x Harvard's course

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    // This prompts the user to insert a credit card number to check
    string cc_number;
    do
    {
        cc_number = get_string("Number: ");
    }
    // If the number have alphabet letters it asks again to input
    while ((isalpha(*cc_number)) || !strcmp(cc_number, ""));

    // Creation of a list of integers for the cc_number
    int numbers[strlen(cc_number)];
    for (int i = 0, n = strlen(cc_number); i < n; i++)
    {
        numbers[i] = cc_number[i] - '0';
    }
    // Identification of the type of credit card from their lenght and starting numbers
    string type;
    int lenght = strlen(cc_number);
    if (lenght > 16 || lenght < 13)
    {
        printf("INVALID\n");
        return 0;
    }
    // MasterCard
    else if (lenght == 16 && numbers[0] == 5 && (numbers[1] == 1 || numbers[1] == 2 || numbers[1] == 3 || numbers[1] == 4
             || numbers[1] == 5))
    {
        type = "MASTERCARD";
    }
    // American Express
    else if (lenght == 15 && numbers[0] == 3 && (numbers[1] == 4 || numbers[1] == 7))
    {
        type = "AMEX";
    }
    // VISA
    else if ((lenght == 13 || lenght == 16) && numbers[0] == 4)
    {
        type = "VISA";
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    // Luhn formula
    int limitation = 0;
    // Limitation is the number of times that the program will need in order to iterate over all the required lists positions
    if (!strcmp(type, "MASTERCARD"))
    {
        limitation = 8;
    }
    else if (!strcmp(type, "AMEX"))
    {
        limitation = 8;
    }
    else if (!strcmp(type, "VISA") && lenght == 16)
    {
        limitation = 8;
    }
    else if (!strcmp(type, "VISA") && lenght == 13)
    {
        limitation = 6;
    }
    // Arithmetic
    int fromPenultimateToSecond[8];
    int fromSecondToLast[8];
    int counter = 1;
    for (int j = 0; j <= limitation - 1; j++)
    {
        // It takes the lenght and then go back by two (If Lenght == 16 then he looks for number on position 14 [penultimate])
        fromPenultimateToSecond[j] = numbers[lenght - 2] * 2;
        // It takes the type of card and then lookout starting from the second one (The first on AMEX and short VISA cases)
        if (strlen(cc_number) == 16)
        {
            fromSecondToLast[j] = numbers[counter];
            counter += 2;
        }
        else if (strlen(cc_number) == 13 || strlen(cc_number) == 15)
        {
            fromSecondToLast[j] = numbers[counter - 1];
            counter += 2;
        }
        lenght -= 2;
    }
    // Adition
    int product = 0;
    for (int m = 0; m <= limitation - 1; m++)
    {
        // This conditional splits the 2 digits number into two 1 digit numbers
        if (fromPenultimateToSecond[m] >= 10)
        {
            product += ((fromPenultimateToSecond[m] % 10) + (fromPenultimateToSecond[m] / 10)) + fromSecondToLast[m];
        }
        else
        {
            product += fromPenultimateToSecond[m] + fromSecondToLast[m];
        }
    }
    if (product % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}