// Helper functions for music
// Marcelo Díaz, CS50x PSET3

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Declaration of the function that will be used to obtain the frequency
int obtain_frequency(char letter, int octave, char accidental);

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char first = fraction[0];
    char second = fraction[2];
    if ((first - '0') == 1 && ((second - '0') == 8))
    {
        return 1;
    }
    else if (((first - '0') == 1) && ((second - '0') == 4))
    {
        return 2;
    }
    else if (((first - '0') == 1) && ((second - '0') == 2))
    {
        return 4;
    }
    else if (((first - '0') == 3) && ((second - '0') == 8))
    {
        return 3;
    }
    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int frequency = 0;
    int lenght = strlen(note);
    char letter;
    int octave;
    char accidental = '\0';
    // Accidental
    if (lenght == 3)
    {
        letter = note[0];
        accidental = note[1];
        octave = (note[2] - '0');
    }
    // Normal note
    else
    {
        letter = note[0];
        octave = (note[1] - '0');
    }
    // This line calls a function that returns the frequency (line 75)
    frequency = obtain_frequency(letter, octave, accidental);
    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// This function calculates the frequency of the notes (i.e A6, A#2, C4)
// It recieves 3 parametres, the letter, the octave and the accidental, it's called from main frequency function
int obtain_frequency(char letter, int octave, char accidental)
{
    // Check on all the possible notes if the octave is 4, in that case it return the frequency inmediately
    float initialVal = 0;
    float frequency;
    switch (letter)
    {
        case 'A':
            initialVal = 440;
            if (octave == 4 && accidental == '\0')
            {
                return initialVal;
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return frequency;
            }
            else if (octave == 4 && accidental == 'b')
            {
                return initialVal / pow(2.0, 1.0 / 12.0);
            }
            break;
        case 'B':
            initialVal = 493.883;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
        case 'C':
            initialVal = 261.626;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
        case 'D':
            initialVal = 293.665;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
        case 'E':
            initialVal = 329.628;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
        case 'F':
            initialVal = 349.228;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
        case 'G':
            initialVal = 391.995;
            if (octave == 4 && accidental == '\0')
            {
                return round(initialVal);
            }
            else if (octave == 4 && accidental == '#')
            {
                frequency = pow(2.0, (1.0 / 12.0)) * initialVal;
                return round(frequency);
            }
            else if (octave == 4 && accidental == 'b')
            {
                return round(initialVal / pow(2.0, 1.0 / 12.0));
            }
            break;
    }
    // This variable stores the boolean value if octave < 4 or otherwise
    bool lessthanfour = false;
    // This variable stores the rest between the octave and four, in order to know the distance between the note and the fourth note
    // If the rest results is less than 0, means that the octave is behind four, so lessthanfour becomes true and the rest becomes +
    float rest = octave - 4;
    // Conditional that determines if the octave it's less than 4
    if (rest < 0)
    {
        lessthanfour = true;
        rest *= -1;
    }
    // Do the math in order to return the frequency, at first place it checks if the note have any accidental
    // No accidental case
    /* If the octave it's less than four means that the note initialVal (obtained from the fourth note) should be multiplied to
    obtain the value of that octave, else: should be divided**/
    if (accidental == '\0')
    {
        if (!lessthanfour)
        {
            frequency = initialVal * pow(2.0, rest);
        }
        else
        {
            frequency = initialVal / pow(2.0, rest);
        }
        return round(frequency);
    }
    // Note with accidental case
    else if (accidental != '\0')
    {
        // More than four octave
        if (!lessthanfour)
        {
            // If the accidental equals # then it should be multiplied
            if (accidental == '#')
            {
                // It multiplies to get the required octave note, and the multiplies again in order to obtain the next semitone
                frequency = initialVal * pow(2.0, rest) * (pow(2.0, 1.0 / 12.0));
            }
            // Else, accidental naturally is equals to b, so it should be divided
            else
            {
                // It multiplies to get the required octave note, and the divides the answer in order to obtain the semitone before
                frequency = initialVal * pow(2.0, rest) / (pow(2.0, 1.0 / 12.0));
            }
            return round(frequency);
        }
        // Less than fourth octave
        else
        {
            if (accidental == '#')
            {
                // It divides to get the required octave note, and the multiplies the answer in order to obtain the next semitone
                frequency = initialVal / pow(2.0, rest) * (pow(2.0, 1.0 / 12.0));
            }
            else
            {
                // It divides to get the required octave note, and the divides the answer in order to obtain the semitone before
                frequency = initialVal / pow(2.0, rest) / (pow(2.0, 1.0 / 12.0));
            }
            return round(frequency);
        }
    }
    // If nothing works (Impossible) just return 1
    return 1;
}
