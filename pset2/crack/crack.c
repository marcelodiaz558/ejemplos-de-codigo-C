// More comfortable pset2 exercise (crack) | This program cracks a encrypted password
// Marcelo Díaz, CS50x Harvard's course

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#define _GNU_SOURCE
#include <crypt.h>
#include <string.h>
string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int check(string key, char salt[2]);

// Principal function, it try the easiests passwords like aaa, bbbb or zzzzz, then the rest of the cases are called on check funct
int main(int argc, string argv[])
{
    // Check if the user input more or less than 1 argument
    if (argc != 2)
    {
        printf("An error has been ocurred: usage ./crack hash\n");
        return 1;
    }
    // Hash given by the user
    string given_Hash = argv[1];
    // Salt of the hash
    char salt[2] = {given_Hash[0], given_Hash[1]};
    // Total possible characters

    // Actual pass being try
    char accumulator[6];
    string new_Hash;
    // This whole loop try all the one letter passwords combinations of any 1-5 lenght password of the same value (i.e aa or zzzzz)
    for (int counter = 0; counter < 52; counter++)
    {
        // Try one letter passwords (i.e a)
        for (int i = 0; i < 52; i++)
        {
            accumulator[0] = letters[counter];
            accumulator[1] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, given_Hash) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c\n", accumulator[0]);
                return 0;
            }
        }
        // Try two letter passwords of same value (i.e bb)
        for (int j = 0; j < 52 * 52; j++)
        {
            accumulator[0] = letters[counter];
            accumulator[1] = letters[counter];
            accumulator[2] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, given_Hash) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c\n", accumulator[0], accumulator[1]);
                return 0;
            }
        }
        // Try three letter passwords of same value (i.e ccc)
        for (int k = 0; k < 52; k++)
        {
            accumulator[0] = letters[counter];
            accumulator[1] = letters[counter];
            accumulator[2] = letters[counter];
            accumulator[3] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, given_Hash) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c\n", accumulator[0], accumulator[1], accumulator[2]);
                return 0;
            }
        }
        // Try four letter passwords of same value (i.e dddd)
        for (int l = 0; l < 52; l++)
        {
            accumulator[0] = letters[counter];
            accumulator[1] = letters[counter];
            accumulator[2] = letters[counter];
            accumulator[3] = letters[counter];
            accumulator[4] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, given_Hash) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c%c\n", accumulator[0], accumulator[1], accumulator[2]
                       , accumulator[3]);
                return 0;
            }
        }
        // Try five letter passwords of same value (i.e eeeee)
        for (int m = 0; m < 52; m++)
        {
            accumulator[0] = letters[counter];
            accumulator[1] = letters[counter];
            accumulator[2] = letters[counter];
            accumulator[3] = letters[counter];
            accumulator[4] = letters[counter];
            accumulator[5] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, given_Hash) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c%c%c\n", accumulator[0], accumulator[1], accumulator[2]
                       , accumulator[3], accumulator[4]);
                return 0;
            }
        }
    }
    // This function check all the other possible combinations
    int result = check(given_Hash, salt);
    // If check returns 1 means that the password has not been discovered
    if (result == 1)
    {
        printf("THE PASSWORD HAS NOT BEEN DISCOVERED\n");
    }
}

// This functions check ALL the combinations of passwords of lenght less than 5 that uses just lower and uppercases letters
int check(string key, char salt[2])
{
    char accumulator[6];
    string new_Hash;
    // Check two letters passwords (i.e Zk)
    for (int i = 1; i < 53; i++)
    {
        accumulator[0] = letters[-1 + i];
        for (int j = 0; j < 52; j++)
        {
            accumulator[1] = letters[j];
            accumulator[2] = '\0';
            new_Hash = crypt(accumulator, salt);
            if (strcmp(new_Hash, key) == 0)
            {
                printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c\n", accumulator[0], accumulator[1]);
                return 0;
            }
        }
    }
    // Check three letter passwords (i.e QlM)
    for (int i = 1; i < 53; i++)
    {
        accumulator[0] = letters[-1 + i];
        for (int j = 0; j < 52; j++)
        {
            accumulator[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                accumulator[2] = letters[k];
                accumulator[3] = '\0';
                new_Hash = crypt(accumulator, salt);
                if (strcmp(new_Hash, key) == 0)
                {
                    printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c\n", accumulator[0], accumulator[1], accumulator[2]);
                    return 0;
                }
            }
        }
    }
    // Check four letter passwords (i.e QamP)
    for (int i = 1; i < 53; i++)
    {
        accumulator[0] = letters[-1 + i];
        for (int j = 0; j < 52; j++)
        {
            accumulator[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                accumulator[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    accumulator[3] = letters[l];
                    accumulator[4] = '\0';
                    new_Hash = crypt(accumulator, salt);
                    if (strcmp(new_Hash, key) == 0)
                    {
                        printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c%c\n", accumulator[0], accumulator[1], accumulator[2]
                               , accumulator[3]);
                        return 0;
                    }
                }
            }
        }
    }
    // Check five letter passwords (i.e adQmZ)
    for (int i = 1; i < 53; i++)
    {
        accumulator[0] = letters[-1 + i];
        for (int j = 0; j < 52; j++)
        {
            accumulator[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                accumulator[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    accumulator[3] = letters[l];
                    for (int m = 0; m < 52; m++)
                    {
                        accumulator[4] = letters[m];
                        accumulator[5] = '\0';
                        new_Hash = crypt(accumulator, salt);
                        if (strcmp(new_Hash, key) == 0)
                        {
                            printf("THE PASSWORD HAS BEEN DISCOVERED: %c%c%c%c%c\n", accumulator[0], accumulator[1], accumulator[2]
                                   , accumulator[3], accumulator[4]);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // If any password was not discovered then exit returning 1 (error)
    return 1;
}