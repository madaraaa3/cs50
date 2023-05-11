#include "helpers.h"
#include <math.h>

void swap(RGBTRIPLE* a, RGBTRIPLE* b);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < height; c++)
        {
            int pixel_avg = round((image[r][c].rgbtBlue + image[r][c].rgbtGreen + image[r][c].rgbtRed) / (float)3);

            image[r][c].rgbtBlue = pixel_avg;
            image[r][c].rgbtGreen = pixel_avg;
            image[r][c].rgbtRed = pixel_avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < height; c++)
        {
            int sred = round(((.189 * image[r][c].rgbtBlue) + (.769 * image[r][c].rgbtGreen) + (.393 * image[r][c].rgbtRed)));
            int sgreen = round(((.168 * image[r][c].rgbtBlue) + (.686 * image[r][c].rgbtGreen) + (.349 * image[r][c].rgbtRed)));
            int sblue = round(((.131 * image[r][c].rgbtBlue) + (.534 * image[r][c].rgbtGreen) + (.272 * image[r][c].rgbtRed)));

            image[r][c].rgbtBlue = fmin(sblue, 255);
            image[r][c].rgbtGreen = fmin(sgreen, 255);
            image[r][c].rgbtRed = fmin(sred, 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            swap(&image[r][c], &image[r][width-1-c]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy[r][c] = image[r][c];
        }
    }

    float tr, tg, tb;
    int count = 0;
    tr = tg = tb = 0;

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            for (int pr = r - 1; pr <= r + 1; pr++)
            {
                for (int pc = c - 1; pc <= c + 1; pc++)
                {
                    if (pc < width && pr < height && pc >= 0 && pr >= 0)
                    {
                        tr += copy[pr][pc].rgbtRed;
                        tg += copy[pr][pc].rgbtGreen;
                        tb += copy[pr][pc].rgbtBlue;
                        count++;
                    }
                }
            }
                image[r][c].rgbtRed = round(tr / count);
                image[r][c].rgbtGreen = round(tg / count);
                image[r][c].rgbtBlue = round(tb / count);
                count = 0;
                tr = tg = tb = 0;
        }

    }
    return;
}

void swap(RGBTRIPLE* a, RGBTRIPLE* b)
{
    RGBTRIPLE temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
