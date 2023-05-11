// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>


string replace(string word);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("you should atleast use one command line argument\n");
        return 1;
    }
}

string replace(string word)
{
    for(int i = 0; i <= strlen(word); i++)
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'o':
                word[i] = '0';
                break;

            case 'i':
                word[i] = '1';
                break;

            default:
                word[i] = word[i];
                break;
        }
    }
    return word;
}
