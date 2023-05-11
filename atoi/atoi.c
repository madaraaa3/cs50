#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int length = strlen(input);
    //Remember you need a base case when creating a recursive function
    if (length == 1)
    {
        return input[0] - '0';
    }
    //Start by getting the index of the last char in the string (the char before the \0).
    char lastchar = input[length-1];
    //Convert this char into its numeric value. Can you subtract some char to do this?
    int num = lastchar - '0';
    //Remove the last char from the string by moving the null terminator one position to the left.
    input[length - 1] = '\0';
    //Return this value plus 10 times the integer value of the new shortened string.
    return num + 10 * convert(input);


}