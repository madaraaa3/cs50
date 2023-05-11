#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text:");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    int grade = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else
        {
            continue;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
        else
        {
            continue;
        }
    }
    return words + 1;
}


int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences += 1;
        }
        else
        {
            continue;
        }
    }
    return sentences;
}