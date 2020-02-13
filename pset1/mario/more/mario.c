// Mario more comfortable, pset1 exercise | The program builds a half pyramid, with a height introduced by the user
// Marcelo Díaz, CS50x Harvard's course

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // This prompts to the user the height desired
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h > 23);
    // Ends the program if height it's equal to zero
    if (h == 0)
    {
        return 0;
    }
    // This first for loop create the rows
    for (int i = 0; i < h; i++)
    {
        // It create the spaces on the first side of the pyramid
        for (int j = h - 1; j > i; j--)
        {
            printf(" ");
        }
        // It create the left side #'s: It evaluates if k<i because I want a pyramid (It print one extra # every execution)
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        // Space between both sides of #'s
        printf("  ");
        // It creates the right side #'s
        for (int m = -1; m < i; m++)
        {
            printf("#");
        }
        // Creation of the row itself
        printf("\n");
    }
}