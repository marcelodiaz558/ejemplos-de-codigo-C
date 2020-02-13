// This program recovers JPEG images from memory card data

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Correct usage: ./recover data");
        return 1;
    }

    // Opens the forensic image
    FILE *memory_Data = fopen(argv[1], "r");
    if (memory_Data == NULL)
    {
        fprintf(stderr, "The forensic image couldn't be opened");
        return 2;
    }

    // Start reading from the file
    uint8_t buffer[512];

    // Variables declaring
    int end = 0;
    int jpeg_found = 0;
    int counter = 0;
    int running = 0;
    int number_of_elements;
    FILE *jpeg = NULL;

    while (end == 0)
    {
        // Reads 512 bytes from the file and it store that on a buffer
        if (jpeg_found == 0)
        {
            number_of_elements = fread(buffer, 1, 512, memory_Data);
        }

        // Checks if the buffer readed its already the end of the file
        if (number_of_elements < 512)
        {
            end = 1;
            fclose(jpeg);
        }

        // Checks if the buffer readed is the header of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if a jpeg have been already founded, in order to close that old file.
            if (jpeg_found != 0)
            {
                fclose(jpeg);
                jpeg_found = 0;
            }

            // Creates the new file
            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            counter++;

            jpeg = fopen(filename, "w");
            if (jpeg == NULL)
            {
                fprintf(stderr, "The JPEG file couldn't be created");
                return 3;
            }

            // Writes the content of the forensic image into the new jpeg
            while (jpeg_found == 0)
            {
                if (running == 1)
                {
                    number_of_elements = fread(buffer, 1, 512, memory_Data);
                    // Check if a new jpeg has been founded
                    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) ||
                        number_of_elements < 512)
                    {
                        jpeg_found = 1;
                        running = 0;
                    }
                }
                if (jpeg_found == 0)
                {
                    fwrite(buffer, 512, 1, jpeg);
                    running = 1;
                }
            }
        }
    }

    fclose(memory_Data);
    // Success
    return 0;
}