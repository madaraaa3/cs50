#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
    }
    FILE *file = fopen(argv[1], "r");
    FILE *img;
    if (file == NULL)
    {
        printf("File is not found");
        return -1;
    }

    BYTE buffer[BLOCK_SIZE];

    char str[8];
    int count = 0;

    while (true)
    {
        int BR = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(str, "%03i.jpg", count);
                img = fopen(str, "w");
                fwrite(buffer, sizeof(BYTE), BR, img);
                count ++;
            }
            else
            {
                fclose(img);
                sprintf(str, "%03i.jpg", count);
                img = fopen(str, "w");
                fwrite(buffer, sizeof(BYTE), BR, img);
                count ++;
            }
        }
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), BR, img);
            if (BR == 0)
            {
                fclose(file);
                fclose(img);
                return 0;
            }
        }

    }
    fclose(img);
    fclose(file);
}