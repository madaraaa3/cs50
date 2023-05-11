#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
     
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < height; c++)
        {
            if (image[r][c].rgbtBlue == 0 && image[r][c].rgbtGreen == 0 && image[r][c].rgbtRed == 0)
            {
                image[r][c].rgbtBlue = 75;
                image[r][c].rgbtGreen = 9;
                image[r][c].rgbtRed = 0;
            }
        }
    }
}
